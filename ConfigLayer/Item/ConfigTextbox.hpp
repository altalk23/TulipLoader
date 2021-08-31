#pragma once
#include <Cacao.hpp>

#include "ConfigPalette.hpp"
#include "ConfigConstant.hpp"

using namespace TLConfigConstant;
using cocos2d::SEL_MenuHandler;
typedef void (*textboxHandler)(std::string);

class TLConfigTextbox : public cocos2d::CCNode {
public:
    static TLConfigTextbox* create(std::string label, textboxHandler onConfirm);

    bool init(std::string label, textboxHandler onConfirm);

    void callback(cocos2d::CCObject*);
    void onSelect(cocos2d::CCObject*);
    void onDeselect(cocos2d::CCObject*);

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;    
    cocos2d::extension::CCScale9Sprite* m_rightSprite;
    cocos2d::CCNode* m_node;
    CCTextInputNode* m_textbox;
    textboxHandler m_callback;
};
