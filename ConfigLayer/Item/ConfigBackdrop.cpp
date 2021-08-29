#include "ConfigBackdrop.hpp"

TLConfigBackdrop* TLConfigBackdrop::create(std::string label) {
    auto ret = new TLConfigBackdrop(); 
    if (ret && ret->init(label)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigBackdrop::init(std::string label) {
    m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_text->setAnchorPoint(cocos2d::CCPoint(0.5, 1));
    m_text->setScale(0.5);
    m_text->setPosition(cocos2d::CCPoint(0.0, -5.0));
    m_text->limitLabelWidth(70.0, 0.5, 0.0);
    m_text->setColor(cocos2d::ccc3(255, 255, 255));
    addChild(m_text, 2);

    m_backdrop = cocos2d::extension::CCScale9Sprite::create("square02b_small.png");
    m_backdrop->setContentSize(cocos2d::CCSizeMake(80.0, m_text->getContentSize().height * m_text->getScaleY() + 10.0));
    m_backdrop->setAnchorPoint(cocos2d::CCPoint(0.5, 1));
    m_backdrop->setColor(cocos2d::ccc3(0, 0, 0));
    m_backdrop->setOpacity(255);
    addChild(m_backdrop);

    return true;
}

void TLConfigBackdrop::increaseBackdrop(float height) {
    auto size = m_backdrop->getContentSize();
    size.height += height;
    m_backdrop->setContentSize(size);
}

cocos2d::CCSize TLConfigBackdrop::getContentSize() {
    return m_backdrop->getContentSize();
}
