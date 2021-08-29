#pragma once
#include <Cacao.hpp>

class TLConfigBackdrop : public cocos2d::CCNode {
public:
    static TLConfigBackdrop* create(std::string label);

    bool init(std::string label);

    void increaseBackdrop(float height);

    cocos2d::CCSize getContentSize();

    cocos2d::CCLabelBMFont* m_text;
    cocos2d::extension::CCScale9Sprite* m_backdrop;
};
