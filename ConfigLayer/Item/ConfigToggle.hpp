#pragma once
#include <Cacao.hpp>

#include "ConfigPalette.hpp"

using cocos2d::SEL_MenuHandler;
typedef void (*toggleHandler)(bool);

class TLConfigToggle : public cocos2d::CCNode {
public:
    static TLConfigToggle* create(std::string label, toggleHandler onSelect);

    bool init(std::string label, toggleHandler onSelect);

    void callback(cocos2d::CCObject*);

    TLConfigToggle* setValue(bool value);
    TLConfigToggle* setDefaultValue(bool value);

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;
    cocos2d::CCNode* m_node;
    cocos2d::CCMenuItemSprite* m_toggle;
    toggleHandler m_callback;
    bool m_value;
};
