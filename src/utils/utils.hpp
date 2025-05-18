#pragma once

// namespace
namespace SuperWorld {

// loading messages
	inline std::vector<std::string> LoadingMessages = {
		"This World is very Super",
		"Loading classic peak",
		"Follow the lore...",
		"The next World is very Mega..."
	};

// logo shit
	inline cocos2d::CCSprite *CovertLogo(cocos2d::CCSprite *gdMainTitle) {
		auto SuperWorld = cocos2d::CCSprite::createWithSpriteFrameName("SuperWorld.png"_spr);
		if (!SuperWorld)
			return nullptr;

		SuperWorld->setPosition({gdMainTitle->getContentSize().width / 2, -13});
		SuperWorld->setScale(0.5f);
		gdMainTitle->setDisplayFrame(cocos2d::CCSpriteFrameCache::get()->spriteFrameByName("Geometry-Dash.png"_spr));
		gdMainTitle->addChild(SuperWorld);
		gdMainTitle->setPositionY(gdMainTitle->getPositionY() + 15.f);
		return SuperWorld;
	}
};