#include "ConfigOverlay.hpp"

using cocos2d::SEL_MenuHandler;

TLConfigOverlay::TLConfigOverlay() : FLAlertLayer() {
    // std::cout << this << std::endl;
    std::cout << *(void**)this << std::endl;
    std::cout << Cacao::typeinfoNameFor(this)<< std::endl;
    m_controlConnected = -1;
    m_joystickConnected = -1;
    m_ZOrder = 0;
    m_noElasticity = true;
}


TLConfigOverlay* TLConfigOverlay::create() {
    if (g_visible) return NULL;
    g_visible = true;

    auto ret = new TLConfigOverlay(); 
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigOverlay::isActive() {
    return g_visible;
}
 
bool TLConfigOverlay::init() {
    CAC_TYPEINFO(0x65d870);
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

void TLConfigOverlay::onClose(cocos2d::CCObject*) {
    std::cout << "overlay onClose" << std::endl;
    setKeypadEnabled(false);
    setTouchEnabled(false);
    setMouseEnabled(false);

    removeFromParentAndCleanup(true);
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
    g_visible = false;

    if (PL != nullptr) {
        for (auto& node : Cacao::ccToVec<CCNode*>(PL->getParent()->getChildren())) {
            std::cout<< Cacao::typeinfoNameFor(node) << std::endl;
            if (!strcmp(Cacao::typeinfoNameFor(node), "10PauseLayer")) node->removeMeAndCleanup();
            
        }
        PL->resume();
    }
}

void TLConfigOverlay::selectThing(cocos2d::CCObject*) {
    std::cout << "selectThing" << std::endl;
}
 
void TLConfigOverlay::keyBackClicked() {
    // onClose(nullptr);
}

void TLConfigOverlay::addCategory(std::string name, TLExtConfigCategory* extCategory) {
    auto category = TLConfigCategory::create(name, extCategory, this);
    category->setPosition(Cacao::anchorPosition(50, -10, 0, 1));
    category->setupItems();
    m_mainLayer->addChild(category);
}

TLConfigOverlay::~TLConfigOverlay() {
    g_visible = false;
    removeAllChildrenWithCleanup(true);
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
}
