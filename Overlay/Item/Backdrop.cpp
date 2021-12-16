#include "Backdrop.hpp"

TLOverlayBackdrop* TLOverlayBackdrop::create(std::string label) {
    auto ret = new TLOverlayBackdrop(); 
    if (ret && ret->init(label)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayBackdrop::init(std::string label) {
    m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_text->setAnchorPoint(cocos2d::CCPoint(0.5, 1));
    m_text->setScale(titleTextScale);
    m_text->setContentSize(titleTextSize);
    m_text->setPosition(cocos2d::CCPoint(0, -nodePadding));
    m_text->limitLabelWidth(horizontalSpriteLength, titleTextScale, 0.0);
    m_text->setColor(TLPalette::Light::text);
    addChild(m_text, 2);

    m_backdrop = cocos2d::extension::CCScale9Sprite::create("square02b_small.png");
    m_backdrop->setContentSize(backdropSize);
    m_backdrop->setAnchorPoint(cocos2d::CCPoint(0.5, 1));
    m_backdrop->setColor(cocos2d::ccc3(0, 0, 0));
    m_backdrop->setOpacity(255);
    addChild(m_backdrop);

    setContentSize(m_backdrop->getContentSize());
    return true;
}

void TLOverlayBackdrop::increaseBackdrop(float height) {
    auto size = m_backdrop->getContentSize();
    size.height += height;
    m_backdrop->setContentSize(size);
    setContentSize(m_backdrop->getContentSize());
}
