#include "OverlayLayer.hpp"

using cocos2d::SEL_MenuHandler;

TLOverlayLayer::TLOverlayLayer() : FLAlertLayer() {
    m_controlConnected = -1;
    m_joystickConnected = -1;
    m_ZOrder = 0;
    m_noElasticity = true;
}


TLOverlayLayer* TLOverlayLayer::create() {
    if (g_visible) return NULL;
    g_visible = true;

    auto ret = new TLOverlayLayer(); 
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayLayer::isActive() {
    return g_visible;
}
 
bool TLOverlayLayer::init() {
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
    if (!cocos2d::CCLayerColor::initWithColor(cocos2d::ccc4(0,0,0,150))) return false;

    registerWithTouchDispatcher();

    setTouchEnabled(true);
    setKeypadEnabled(true);
    setMouseEnabled(true);

    m_mainLayer = cocos2d::CCLayer::create();
    addChild(m_mainLayer);

    m_buttonMenu = cocos2d::CCMenu::create();
    m_buttonMenu->setPosition(cocos2d::CCPoint(0, 0));
    m_mainLayer->addChild(m_buttonMenu, 1);

    for (auto& [name, category] : TLConfigManager::sharedManager()->getAllCategories()) {
        addCategory(name, category);
    }

    if (PL != nullptr) PL->pauseGame(true);

    return true;
}

void TLOverlayLayer::onClose(cocos2d::CCObject*) {
    setKeypadEnabled(false);
    setTouchEnabled(false);
    setMouseEnabled(false);

    removeFromParentAndCleanup(true);
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
    g_visible = false;

    if (PL != nullptr) {
        for (auto& node : Cacao::ccToVec<CCNode*>(PL->getParent()->getChildren())) {
            if (!strcmp(Cacao::typeinfoNameFor(node), "10PauseLayer")) node->removeMeAndCleanup();
        }
        PL->resume();
    }
}

void TLOverlayLayer::keyBackClicked() {
    // onClose(nullptr);
}

void TLOverlayLayer::addCategory(std::string name, TLCategoryConfig* extCategory) {
    auto category = TLOverlayCategory::create(name, extCategory, this);
    category->setPosition(Cacao::anchorPosition(50, -10, 0, 1));
    category->setupItems();
    m_mainLayer->addChild(category);
}

TLOverlayLayer::~TLOverlayLayer() {
    g_visible = false;
    removeAllChildrenWithCleanup(true);
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
}
