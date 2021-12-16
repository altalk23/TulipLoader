#pragma once
#include <Cacao>

#include <Palette.hpp>
#include <Constant.hpp>

#include <ConfigCategory.hpp>

using namespace TLConstant;
using cocos2d::SEL_MenuHandler;

class TLOverlayToggle : public cocos2d::CCNode {
public:
    static TLOverlayToggle* create(TLToggleConfig* config);

    bool init(TLToggleConfig* config);

    void callback(cocos2d::CCObject*);

    bool& value();

    void fadeColor();
    void switchColor();

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;
    cocos2d::CCNode* m_node;
    cocos2d::CCMenuItemSprite* m_toggle;
    TLToggleConfig* m_config;
};
