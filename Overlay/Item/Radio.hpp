#pragma once
#include <Cacao>

#include <Palette.hpp>
#include <Constant.hpp>

#include <ConfigCategory.hpp>

using namespace TLConstant;
using cocos2d::SEL_MenuHandler;

class TLOverlayRadio : public cocos2d::CCNode {
public:
    static TLOverlayRadio* create(TLRadioConfig* config);

    bool init(TLRadioConfig* config);

    void callback(cocos2d::CCObject*);

    int& value();

    void fadeColor();
    void switchColor();
    
    std::vector<cocos2d::CCMenuItemSprite*> m_options;
    TLRadioConfig* m_config;
};
