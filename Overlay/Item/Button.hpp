#pragma once
#include <Cacao>

#include <Palette.hpp>
#include <Constant.hpp>

#include <ConfigCategory.hpp>

using namespace TLConstant;
using cocos2d::SEL_MenuHandler;

class TLOverlayButton : public cocos2d::CCNode {
public:
    static TLOverlayButton* create(TLButtonConfig* config);

    bool init(TLButtonConfig* config);

    void callback(cocos2d::CCObject*);

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;    
    cocos2d::extension::CCScale9Sprite* m_leftSprite;
    cocos2d::CCNode* m_node;
    cocos2d::CCMenuItemSprite* m_button;
    TLButtonConfig* m_config;
};
