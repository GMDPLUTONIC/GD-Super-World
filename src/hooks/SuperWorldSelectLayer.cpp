#include <Geode/Geode.hpp>
#include "SuperWorldSelectLayer.h"

using namespace geode::prelude;

SuperWorldSelectLayer* SuperWorldSelectLayer::create(int page) {
	auto ret = new SuperWorldSelectLayer();
	if (ret && ret->init(page)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
};

CCScene* SuperWorldSelectLayer::scene(int page) {
	auto layer = SuperWorldSelectLayer::create(page);
	auto scene = CCScene::create();
	scene->addChild(layer);
	return scene;
}

bool SuperWorldSelectLayer::init(int page)
{
	if (!LevelSelectLayer::init(page)) return false;

	m_scrollLayer->m_dynamicObjects->removeAllObjects();

	auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

	for (CCSprite* dot : dotsArray) {
		dot->removeFromParent();
	}
	m_scrollLayer->m_dots->removeAllObjects();

	std::vector<std::tuple<int, const char*>> levels = {
		{1, ""},
		{2, ""},
		{3, ""},
		{4, ""},
		{5, ""},
		{6, ""},
		{7, ""},
		{8, ""},
		{9, ""}
	};

	auto GLM = GameLevelManager::sharedState();
	for (auto [id, name] : levels) {
		auto level = GLM->getMainLevel(id, true);

		m_scrollLayer->m_dynamicObjects->addObject(level);
	}

	auto comingSoon = GJGameLevel::create();
	comingSoon->m_levelID = -1;
	m_scrollLayer->m_dynamicObjects->addObject(comingSoon);
	
	auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
	m_scrollLayer->addChild(batchNode, 5);

	for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
		auto sprite = CCSprite::create("smallDot.png");
		batchNode->addChild(sprite);
		m_scrollLayer->m_dots->addObject(sprite);
	}

	m_scrollLayer->updateDots(0.f);
//	m_scrollLayer->updatePages(0.f);
	updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(page % 9),
		m_scrollLayer->m_dynamicObjects->objectAtIndex(page));
//	m_scrollLayer->repositionPagesLooped();

	return true;
}