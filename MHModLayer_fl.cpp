#include "MHModLayer.h"

using cocos2d::SEL_MenuHandler;

MHModLayer::MHModLayer() : FLAlertLayer() {
    m_controlConnected = -1;
    m_joystickConnected = -1;
    m_ZOrder = 0;
    m_noElasticity = true;
}

MHModLayer* MHModLayer::create() {
	auto ret = new MHModLayer(); 
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool MHModLayer::init() {
	CAC_TYPEINFO(0x65d870);
	if (CCLayerColor::initWithColor(cocos2d::ccc4(0,0,0,150))) {

        registerWithTouchDispatcher();
        cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);

        setTouchEnabled(true);
        setKeypadEnabled(true);

        m_mainLayer = CCLayer::create();
        addChild(m_mainLayer);

        auto prevMenu = cocos2d::CCMenu::create();
		m_mainLayer->addChild(prevMenu);
		auto prevSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
		m_prevArrow = CCMenuItemSpriteExtra::create(
			prevSprite, nullptr, this, (SEL_MenuHandler)(&MHModLayer::onPrevPage)
		);
		prevMenu->addChild(m_prevArrow);
		auto prevPos = m_mainLayer->convertToNodeSpace(Cacao::anchorPosition(24.0, 0.0, 0.0, 0.5));
		prevMenu->setPosition(prevPos);

		auto nextMenu = cocos2d::CCMenu::create();
		m_mainLayer->addChild(nextMenu);
		auto nextSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
		nextSprite->setFlipX(true);
		m_nextArrow = CCMenuItemSpriteExtra::create(
			nextSprite, nullptr, this, (SEL_MenuHandler)(&MHModLayer::onNextPage)
		);
		nextMenu->addChild(m_nextArrow);
		auto nextPos = m_mainLayer->convertToNodeSpace(Cacao::anchorPosition(-24.0, 0.0, 1.0, 0.5));
		nextMenu->setPosition(nextPos);

		auto backdrop = cocos2d::extension::CCScale9Sprite::create("GJ_square03.png");
        backdrop->setContentSize(cocos2d::CCSizeMake(440.0, 290.0));
        backdrop->setPosition(Cacao::addedPosition(0.0, 0.0));
        m_mainLayer->addChild(backdrop, -2);

        loadPage(0);
    }
    return true;
}

void MHModLayer::onNextPage(cocos2d::CCObject*) {
	loadPage(m_page+1);
}
void MHModLayer::onPrevPage(cocos2d::CCObject*) {
	loadPage(m_page-1);
}

void MHModLayer::loadPage(int page) {
	std::cout << "loadPage: " << page << std::endl;
	m_page = page;
}

void MHModLayer::onClose(cocos2d::CCObject*) {
    setKeypadEnabled(false);
    setTouchEnabled(false);
    removeFromParentAndCleanup(true);
}

void MHModLayer::keyBackClicked() {
    onClose(nullptr);
}
