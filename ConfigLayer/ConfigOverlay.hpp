#pragma once
#include <Cacao.hpp>
#include "ConfigCategory.hpp"
#include "ConfigManager.hpp"
#include "Item/ConfigBackdrop.hpp"
#include "ExtConfigCategory.hpp"

using cocos2d::SEL_MenuHandler;

class TLConfigOverlay : public FLAlertLayer {
public:
    static TLConfigOverlay* create();
    TLConfigOverlay();

protected:
    static inline bool g_visible;

public:
    static bool isActive();
    bool init();

    void onClose(cocos2d::CCObject*);
    void keyBackClicked();
    // void FLAlert_Clicked(FLAlertLayer*, bool);

    void addCategory(std::string name, TLExtConfigCategory* extCategory);

    void selectThing(cocos2d::CCObject*);
    ~TLConfigOverlay();

};
