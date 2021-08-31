#pragma once
#include <Cacao.hpp>

#include "ConfigPalette.hpp"
#include "ConfigConstant.hpp"

using namespace TLConfigConstant;
using cocos2d::SEL_MenuHandler;
typedef void (*radioHandler)(int);

class TLConfigRadio : public cocos2d::CCNode {
public:
    static TLConfigRadio* create(std::vector<std::string> labels, radioHandler onSelect);

    bool init(std::vector<std::string> labels, radioHandler onSelect);

    void callback(cocos2d::CCObject*);

    TLConfigRadio* setValue(int value);
    TLConfigRadio* setDefaultValue(int value);

    std::vector<cocos2d::CCMenuItemSprite*> m_options;
    radioHandler m_callback;
    int m_value;
};
