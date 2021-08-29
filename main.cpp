#define CAC_PROJ_NAME "Megahack uwu"
#include <CacKit>
#include <iostream>
// #include "innerworkings/MacDylib.h"
// #include "Manager.h"
#include "Manager.hpp"
#include "ListLayer.hpp"
#include "ModLayer.hpp"
#include "ConfigLayer/ConfigOverlay.hpp"

// class TLDropdown : public GJDropDownLayer {
// public:
//     CAC_CREATE(TLDropdown);

//     bool init() {
//         CAC_TYPEINFO(0x6754b0); // don't question it
//         if (GJDropDownLayer::init("Mods", 220.0)) {
//             std::cout << "size is " << TLManager::sharedManager()->m_mods.size() << "\n";
//             for (auto& i : TLManager::sharedManager()->m_mods) {
//                 std::cout << "name is " << i.second->getName() << "\n";
//             }
//         }
//         return true;
//     }
// }; 




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

void dispatchKeyboardMSGHook(cocos2d::CCKeyboardDispatcher* self, int code, bool press) {
    if (code == 9 && press) {
        if (!TLConfigOverlay::isActive() && 
            !cocos2d::CCDirector::sharedDirector()->getIsTransitioning()) 
                TLConfigOverlay::create()->show();
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
