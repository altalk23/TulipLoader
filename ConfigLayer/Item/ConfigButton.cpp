#include "ConfigButton.hpp"

TLConfigButton* TLConfigButton::create(std::string label, buttonHandler onClick) {
    auto ret = new TLConfigButton(); 
    if (ret && ret->init(label, onClick)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigButton::init(std::string label, buttonHandler onClick) {
    m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_text->setPosition(cocos2d::CCPoint(8, 7));
    m_text->setContentSize(cocos2d::CCSizeMake(80, 8));
    m_text->setScale(0.4);
    m_text->limitLabelWidth(64.0, 0.4, 0.0);
    m_text->setColor(TLConfigPalette::textDark);

    auto textHeight = m_text->getContentSize().height * m_text->getScaleY();

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setScale(0.05);
    m_bottomSprite->setContentSize(cocos2d::CCSizeMake(70.0 / 0.05, 1.0 / 0.05));
    m_bottomSprite->setColor(TLConfigPalette::primaryDark);
    m_bottomSprite->setOpacity(255);
    m_bottomSprite->setPosition(cocos2d::CCPoint(40.0, 5));

    m_leftSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_leftSprite->setScale(0.05);
    m_leftSprite->setContentSize(cocos2d::CCSizeMake(1.0 / 0.05, (textHeight + 2) / 0.05));
    m_leftSprite->setColor(TLConfigPalette::primaryDark);
    m_leftSprite->setOpacity(255);
    m_leftSprite->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_leftSprite->setPosition(cocos2d::CCPoint(5, 5));

    m_node = cocos2d::CCNode::create();
    m_node->addChild(m_bottomSprite);
    m_node->addChild(m_leftSprite);
    m_node->addChild(m_text);
    m_node->setContentSize(cocos2d::CCSizeMake(80.0, textHeight + 9));
    m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_button = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLConfigButton::callback));

    m_callback = onClick;

    setContentSize(m_node->getContentSize());
    return true;
}

void TLConfigButton::callback(cocos2d::CCObject* sender) {
    m_bottomSprite->setColor(TLConfigPalette::primaryLight);
    m_leftSprite->setColor(TLConfigPalette::primaryLight);
    m_text->setColor(TLConfigPalette::textLight);

    auto bottomTintTo = cocos2d::CCTintTo::create(0.4, 
        TLConfigPalette::primaryDark.r, 
        TLConfigPalette::primaryDark.g, 
        TLConfigPalette::primaryDark.b);

    auto leftTintTo = cocos2d::CCTintTo::create(0.4, 
        TLConfigPalette::primaryDark.r, 
        TLConfigPalette::primaryDark.g, 
        TLConfigPalette::primaryDark.b);

    auto textTintTo = cocos2d::CCTintTo::create(0.4, 
        TLConfigPalette::textDark.r, 
        TLConfigPalette::textDark.g, 
        TLConfigPalette::textDark.b);

    m_bottomSprite->runAction(bottomTintTo);
    m_leftSprite->runAction(leftTintTo);
    m_text->runAction(textTintTo);

    m_callback();
} 


