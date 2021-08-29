#include "ConfigToggle.hpp"

TLConfigToggle* TLConfigToggle::create(std::string label, SEL_MenuHandler onSelect) {
    auto ret = new TLConfigToggle(); 
    if (ret && ret->init(label, onSelect)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigToggle::init(std::string label, SEL_MenuHandler onSelect) {
    m_onText = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_onText->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_onText->setPosition(cocos2d::CCPoint(7, 7));
    m_onText->setScale(0.4);
    m_onText->limitLabelWidth(66.0, 0.4, 0.0);
    m_onText->setColor(cocos2d::ccc3(255, 255, 255));

    m_offText = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_offText->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_offText->setPosition(cocos2d::CCPoint(7, 7));
    m_offText->setScale(0.4);
    m_offText->limitLabelWidth(66.0, 0.4, 0.0);
    m_offText->setColor(cocos2d::ccc3(150, 150, 150));

    auto textHeight = m_onText->getContentSize().height * m_onText->getScaleY();

    m_onSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_onSprite->setScale(0.05);
    m_onSprite->setContentSize(cocos2d::CCSizeMake(70.0 / 0.05, 1.0 / 0.05));
    m_onSprite->setColor(cocos2d::ccc3(200, 0, 200));
    m_onSprite->setOpacity(255);
    m_onSprite->setPosition(cocos2d::CCPoint(40.0, 5));

    m_offSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_offSprite->setScale(0.05);
    m_offSprite->setContentSize(cocos2d::CCSizeMake(70.0 / 0.05, 1.0 / 0.05));
    m_offSprite->setColor(cocos2d::ccc3(100, 0, 100));
    m_offSprite->setOpacity(255);
    m_offSprite->setPosition(cocos2d::CCPoint(40.0, 5));



    m_onNode = cocos2d::CCNode::create();
    m_onNode->addChild(m_onSprite);
    m_onNode->addChild(m_onText);
    m_onNode->setContentSize(cocos2d::CCSizeMake(80.0, textHeight + 9));
    m_onNode->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_offNode = cocos2d::CCNode::create();
    m_offNode->addChild(m_offSprite);
    m_offNode->addChild(m_offText);
    m_offNode->setContentSize(cocos2d::CCSizeMake(80.0, textHeight + 9));
    m_offNode->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_toggler = CCMenuItemToggler::create(m_offNode, m_onNode, this, onSelect);
    m_toggler->setSizeMult(1.0);
    m_toggler->m_offButton->setSizeMult(1.0);
    m_toggler->m_onButton->setSizeMult(1.0);
    // m_toggler = Cacao::createToggler(this, onSelect);

    

    // auto menu = cocos2d::CCMenu::create();
    // menu->addChild(toggler);
    // menu->setPosition(cocos2d::CCPoint(0.0, -10.0));
    // menu->addChild(m_text);

    // addChild(menu);
    // addChild(m_text);

    return true;
}

TLConfigToggle* TLConfigToggle::setValue(bool value) {
    m_toggler->toggle(value);
    return this;
}
TLConfigToggle* TLConfigToggle::setDefaultValue(bool value) {
    return this;
}

cocos2d::CCSize TLConfigToggle::getContentSize() {
    return m_onNode->getContentSize();
    // return cocos2d::CCNode::getContentSize();
}
