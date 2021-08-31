#pragma once
#include <Cacao.hpp>

#include "ConfigPalette.hpp"
#include "ConfigConstant.hpp"

using namespace TLConfigConstant;
using cocos2d::SEL_MenuHandler;
typedef void (*buttonHandler)();

class TLConfigButton : public cocos2d::CCNode {
public:
    static TLConfigButton* create(std::string label, buttonHandler onClick);

    bool init(std::string label, buttonHandler onClick);

    void callback(cocos2d::CCObject*);

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_bottomSprite;    
    cocos2d::extension::CCScale9Sprite* m_leftSprite;
    cocos2d::CCNode* m_node;
    cocos2d::CCMenuItemSprite* m_button;
    buttonHandler m_callback;
};
