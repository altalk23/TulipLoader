#include <Cacao.hpp>
#include "MHDropDown.h"
#include "MHManager.h"

using namespace cocos2d;

bool MHDropDown::init() {
	CAC_TYPEINFO(0x6754b0); // don't question it

    if (GJDropDownLayer::init("Mods", 220.0)) {
        std::cout << "size is " << MHManager::sharedManager()->m_mods.size() << std::endl;
        for (auto& [name, mod] : MHManager::sharedManager()->m_mods) {
            std::cout << "name is " << mod->getName() << std::endl;
        }
    }

    return true;
}

void MHDropDown::customSetup() {
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto menu = CCMenu::create();
	m_mainLayer->addChild(menu);

	for (int i = 0; i < 10; ++i) {
		auto optionsBtn = CCMenuItemSpriteExtra::create(
			ButtonSprite::create("Options", 150, 150, 1.0f, true),
			nullptr,
			this,
			(SEL_MenuHandler)(&MHDropDown::onOptions)
		);
		menu->addChild(optionsBtn);
	}

	
	auto aboutBtn = CCMenuItemSpriteExtra::create(
		ButtonSprite::create("About", 150, 150, 1.0f, true),
		nullptr,
		this,
		(SEL_MenuHandler)(&MHDropDown::onAbout)
	);
	menu->addChild(aboutBtn);

	menu->alignItemsVerticallyWithPadding(20.0f);

	m_div = CCNode::create();
    m_div->setPosition({winSize.width / 2, 0});

    auto texture = new CCTexture2D();
    texture->autorelease();
    const unsigned char data[3] = {255, 255, 255};
    texture->initWithData(data, kCCTexture2DPixelFormat_RGB888, 1, 1, {1, 1});
    texture->setAliasTexParameters();
    auto stencil = CCSprite::createWithTexture(texture);
    stencil->setScaleX(winSize.width / stencil->getContentSize().width);
    stencil->setScaleY(100 / stencil->getContentSize().height);
    stencil->setAnchorPoint({0, 0});

    auto clip = CCClippingNode::create(stencil);
    clip->addChild(m_div);
    clip->setAlphaThreshold(0.1f);
    m_mainLayer->addChild(clip);
}

void MHDropDown::exitLayer(CCObject* ob) {
	// auto parent = static_cast<LoaderLayer*>(this->getParent());
	// parent->scheduleUpdate();
	// parent->setMouseEnabled(true);
	GJDropDownLayer::exitLayer(ob);
	// this->setKeypadEnabled(false);
	// CCDirector::sharedDirector()->getTouchDispatcher()->setForcePrio(false);
	// this->disableUI();
	// this->hideLayer(false);
}

void MHDropDown::onOptions(CCObject* ob) {
	
}

void MHDropDown::onAbout(CCObject* ob) {
	
}
