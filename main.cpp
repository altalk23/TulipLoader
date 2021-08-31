#define CAC_PROJ_NAME "Megahack uwu"
#include <CacKit>
#include <iostream>
#include "Manager.hpp"
#include "ListLayer.hpp"
#include "ModLayer.hpp"
#include "ConfigLayer/ConfigOverlay.hpp"

class $redirect(CCTextInputNode) {
public:
    void onClickTrackNode(bool state) override {
        auto configTextbox = reinterpret_cast<TLConfigTextbox*>(getUserObject());
        if (configTextbox != nullptr && !strcmp(Cacao::typeinfoNameFor(configTextbox), "15TLConfigTextbox")) {
            if (state) configTextbox->onSelect(this);
            else configTextbox->onDeselect(this);
        }
        return $CCTextInputNode::onClickTrackNode(state);
    }
    bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* p0, char const* p1, int p2) override {
        if ((int)*p1 == 27) {
            onClickTrackNode(false);
            return true;
        }
        else if ((int)*p1 == 13) {
            auto configTextbox = reinterpret_cast<TLConfigTextbox*>(getUserObject());
            if (configTextbox != nullptr && !strcmp(Cacao::typeinfoNameFor(configTextbox), "15TLConfigTextbox")) {
                configTextbox->callback(this);
            }
            onClickTrackNode(false);
            return true;
        }
        return $CCTextInputNode::onTextFieldInsertText(p0, p1, p2);
    }
} CCTextInputNodeHook;

class $redirect(MenuLayer) {
public:
    void onMoreGames(CCObject* sender) {
        // auto drop = TLDropDown::create();
        // cac_this->addChild(drop,999);
        // drop->showLayer(false);

        auto list = TLModLayer::create();
        addChild(list, 999);
        list->showLayer(false);
    }
} MenuLayerHook;

TLConfigOverlay* g_overlay;

void dispatchKeyboardMSGHook(cocos2d::CCKeyboardDispatcher* self, int code, bool press) {
    if (code == 9 && press) {
        std::cout << "tab press" << std::endl;
        if (!TLConfigOverlay::isActive() && !cocos2d::CCDirector::sharedDirector()->getIsTransitioning()) {
            std::cout << "create overlay" << std::endl;
            g_overlay = TLConfigOverlay::create();
            g_overlay->show();
        }
        else if (TLConfigOverlay::isActive()) {
            std::cout << "destroy overlay" << std::endl;
            g_overlay->onClose(nullptr);
            g_overlay = nullptr;
        }
    }
    if (code == 65 && press) {
        auto scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();

        std::cout << scene->getChildrenCount() << std::endl;

        for (auto node: Cacao::ccToVec<cocos2d::CCNode*>(scene->getChildren())) {
            std::cout << Cacao::typeinfo_name_for(node) << " " << node << std::endl;
        }
    }
    // std::cout << "msg " << code << " " << press << std::endl;
    ORIG(dispatchKeyboardMSGHook, 0xe8190)(self, code, press);
}

void inject() {
    m->registerHook(getBase()+0xe8190, dispatchKeyboardMSGHook);

    std::cout << "Loading mods from the mod folder" << std::endl;
    TLManager::sharedManager();
    std::cout << "Loading Loader" << std::endl;
}

$apply();
