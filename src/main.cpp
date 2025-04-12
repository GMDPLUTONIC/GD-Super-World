#include "utils/utils.hpp"
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/MenuGameLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>
using namespace geode::prelude;

class $modify(MenuLayerLogo, MenuLayer) {
	bool init() {
		if (!MenuLayer::init())
			return false;
		if (CCNode *gdMainTitle = this->getChildByID("main-title"))
			if (CCSprite *Logoimg = typeinfo_cast<CCSprite *>(gdMainTitle)) {
				SuperWorld::CovertLogo(Logoimg);
			};
		return true;
	}
};

class $modify(LoadingLayerLogo, LoadingLayer) {
	bool init(bool fromReload) {

		if (!LoadingLayer::init(fromReload))
			return false;

		auto searchPathRoot = dirs::getModRuntimeDir() / Mod::get()->getID() / "resources";
		CCFileUtils::sharedFileUtils()->addSearchPath(searchPathRoot.string().c_str());

		m_textArea->setString(SuperWorld::LoadingMessages.at(rand() % (SuperWorld::LoadingMessages.size() - 0)).c_str());
		
		auto SFC = CCSpriteFrameCache::get();
		auto TFC = CCTextureCache::get();
		auto director = CCDirector::get();
		auto winSize = director->getWinSize();
		auto GM = GameManager::sharedState();

		SFC->addSpriteFramesWithFile("SuperWorld-Sheet.plist"_spr);

		if (CCNode *gdMainTitle = this->getChildByID("gd-logo"))
			if (CCSprite *Logoimg = typeinfo_cast<CCSprite *>(gdMainTitle)) {
				SuperWorld::CovertLogo(Logoimg);
			};
		if (!GM->getUGV("30")) {
			GM->setUGV("30", true);
		}
		return true;
	}
};

$on_mod(Loaded) {
	auto PackPath = geode::Mod::get()->getResourcesDir().string();
	CCFileUtils::get()->addTexturePack(CCTexturePack{.m_id = Mod::get()->getID(), .m_paths = {PackPath}});
}

#include <Geode/modify/GManager.hpp>
using namespace geode::prelude;

class $modify(SuperWorldSaveManager, GManager) {
	void setup() {
		auto compare = std::string(m_fileName);
		compare.insert(std::string_view(compare).find(".dat"), "SuperWorld");
		m_fileName = compare;
		GManager::setup();
	}
};

class $modify(SuperWorldMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (!Mod::get()->setSavedValue("seen-intro", true)) {
            FLAlertLayer* popup = FLAlertLayer::create("Geometry Dash SuperWorld", "Welcome to <cf>Geometry Dash SuperWorld</c>.", "Close");
            popup->m_scene = this;
            popup->show();
        }

		if(auto profileMenu = getChildByID("profile-menu"))
			profileMenu->setVisible(false);

		if(auto playerUsername = getChildByID("player-username"))
			playerUsername->setVisible(false);

		auto mainMenu = getChildByID("main-menu");

		if(auto editorButton = static_cast<CCMenuItemSpriteExtra*>(mainMenu->getChildByID("editor-button")))
		editorButton->setNormalImage(CCSprite::createWithSpriteFrameName("Creator-Btn.png"_spr));

		auto rightMenu = static_cast<CCMenu*>(this->getChildByID("right-side-menu"));

		auto creditSprite = CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png");

        if (auto dailyChests = static_cast<CCMenuItemSpriteExtra *>(rightMenu->getChildByID("daily-chest-button")))
            dailyChests->setNormalImage(creditSprite);

		rightMenu->updateLayout();
		
		return true;
	}
	void onDaily(CCObject* sender) {
		FLAlertLayer::create("Credits:", "<cg>ZapManiac:</c> Everything except for the mod.\n<cf>GMP:</c> Mod Dev.", "Close")->show();
	}

	void onCreator(CCObject* sender) {
	    
	}
};