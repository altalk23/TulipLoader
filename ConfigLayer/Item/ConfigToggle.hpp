#pragma once
#include <Cacao.hpp>

using cocos2d::SEL_MenuHandler;

class TLConfigToggle : public cocos2d::CCNode {
public:
    static TLConfigToggle* create(std::string label, SEL_MenuHandler onSelect);

    bool init(std::string label, SEL_MenuHandler onSelect);

    TLConfigToggle* setValue(bool value);
    TLConfigToggle* setDefaultValue(bool value);

    cocos2d::CCSize getContentSize();

    cocos2d::CCLabelBMFont* m_onText;
    cocos2d::CCLabelBMFont* m_offText;
    cocos2d::extension::CCScale9Sprite* m_onSprite;
    cocos2d::extension::CCScale9Sprite* m_offSprite;
    cocos2d::CCNode* m_onNode;
    cocos2d::CCNode* m_offNode;
    CCMenuItemToggler* m_toggler;
    // cocos2d::CCMenu m_menu;
};
