#pragma once
#include <Cacao>

#include <Palette.hpp>
#include <Constant.hpp>

#include <ConfigCategory.hpp>

using namespace TLConstant;

class TLOverlayBackdrop : public cocos2d::CCNode {
public:
    static TLOverlayBackdrop* create(std::string label);

    bool init(std::string label);

    void increaseBackdrop(float height);

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_backdrop;
};
