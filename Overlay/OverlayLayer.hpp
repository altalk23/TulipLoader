#pragma once
#include <Cacao>
#include <Item/Category.hpp>
#include <ConfigManager.hpp>

using cocos2d::SEL_MenuHandler;

class TLOverlayCategory;

class TLOverlayLayer : public FLAlertLayer {
public:
    static TLOverlayLayer* create();
    TLOverlayLayer();

protected:
    static inline bool g_visible;

public:
    static bool isActive();
    bool init();

    void onClose(cocos2d::CCObject*);
    void keyBackClicked();

    void addCategory(std::string name, TLCategoryConfig* extCategory);

    ~TLOverlayLayer();

};
