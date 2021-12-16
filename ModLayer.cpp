#include "ModLayer.hpp"

TLModLayer* TLModLayer::create() {
    auto ret = new TLModLayer(); 
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLModLayer::init() {
    m_mods = cocos2d::CCArray::create();
    for (auto& [uuid, mod] : TLManager::sharedManager()->m_mods) {
        m_mods->addObject(new TLModInfo(uuid, mod));
    }

    if (GJDropDownLayer::init("Mods", 220.0)) return true;
    return false;
}

void TLModLayer::customSetup() {
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
    //honestly i don't think we need the pages yet
    // auto prevMenu = cocos2d::CCMenu::create();
    // m_mainLayer->addChild(prevMenu);
    // auto prevSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    // m_prevArrow = CCMenuItemSpriteExtra::create(
    //  prevSprite, nullptr, this, menu_selector(TLModLayer::onPrevPage)
    // );
    // prevMenu->addChild(m_prevArrow);
    // m_prevArrow->onEnterTransitionDidFinish();
    // auto prevPos = m_mainLayer->convertToNodeSpace(Cacao::anchorPosition(24.0, 0.0, 0.0, 1.5));
    // prevMenu->setPosition(prevPos);

    // auto nextMenu = cocos2d::CCMenu::create();
    // m_mainLayer->addChild(nextMenu);
    // auto nextSprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    // nextSprite->setFlipX(true);
    // m_nextArrow = CCMenuItemSpriteExtra::create(
    //  nextSprite, nullptr, this, menu_selector(TLModLayer::onNextPage)
    // );
    // nextMenu->addChild(m_nextArrow);
    // auto nextPos = m_mainLayer->convertToNodeSpace(Cacao::anchorPosition(-24.0, 0.0, 1.0, 1.5));
    // nextMenu->setPosition(nextPos);

    m_pageLabel = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
    m_pageLabel->setAnchorPoint(cocos2d::CCPoint(1.0, 1.0));
    m_pageLabel->setPosition(Cacao::anchorPosition(-7.0, -4.0, 1.0, 2.0));
    m_mainLayer->addChild(m_pageLabel);

    loadPage(0);
}

void TLModLayer::onNextPage(cocos2d::CCObject*) {
    loadPage(m_page+1);
}
void TLModLayer::onPrevPage(cocos2d::CCObject*) {
    loadPage(m_page-1);
}

void TLModLayer::loadPage(int page) {
    // std::cout << "loadPage: " << page << std::endl;
    // std::cout << m_mods->count() << std::endl;
    m_page = page;

    m_listLayer->removeChildByTag(9, true);
    auto listLayer = TLListLayer::create(m_mods);
    listLayer->setTag(9);
    m_listLayer->addChild(listLayer, 6);
}

TLModLayer::~TLModLayer() {
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
}
