#pragma once
#include <Cacao>

#include <Palette.hpp>
#include <Constant.hpp>

#include <ConfigCategory.hpp>

using namespace TLConstant;

class TLOverlayTextbox : public cocos2d::CCNode {
public:
    static TLOverlayTextbox* create(TLTextboxConfig* config);

    bool init(TLTextboxConfig* config);

    void callback(cocos2d::CCObject*);
    void onSelect(cocos2d::CCObject*);
    void onDeselect(cocos2d::CCObject*);

    std::string& value();

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;    
    cocos2d::extension::CCScale9Sprite* m_rightSprite;
    cocos2d::CCNode* m_node;
    CCTextInputNode* m_textbox;
    TLTextboxConfig* m_config;
};
