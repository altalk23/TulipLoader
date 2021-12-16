#include "Button.hpp"

TLOverlayButton* TLOverlayButton::create(TLButtonConfig* config) {
    auto ret = new TLOverlayButton(); 
    if (ret && ret->init(config)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayButton::init(TLButtonConfig* config) {
	auto label = config->m_label;
	m_config = config;

    m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_text->setPosition(cocos2d::CCPoint(nodePadding + textHorizontalPadding, textVerticalPadding));
    m_text->setScale(textScale);
    m_text->setContentSize(textSize);
    m_text->setColor(TLPalette::Dark::text);
    m_text->limitLabelWidth(textWidth, textScale, 0);

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_bottomSprite->setPosition(cocos2d::CCPoint(nodePadding, 0));
    m_bottomSprite->setScale(spriteScale);
    m_bottomSprite->setContentSize(horizontalSpriteSize);
    m_bottomSprite->setColor(TLPalette::Dark::primary);
    m_bottomSprite->setOpacity(255);

    m_leftSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_leftSprite->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    m_leftSprite->setPosition(cocos2d::CCPoint(nodePadding, 0));
    m_leftSprite->setScale(spriteScale);
    m_leftSprite->setContentSize(verticalSpriteSize);
    m_leftSprite->setColor(TLPalette::Dark::primary);
    m_leftSprite->setOpacity(255);

    m_node = cocos2d::CCNode::create();
    m_node->addChild(m_bottomSprite);
    m_node->addChild(m_leftSprite);
    m_node->addChild(m_text);
    m_node->setContentSize(nodeBottomSize);
    m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_button = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLOverlayButton::callback));


    setContentSize(m_node->getContentSize());
    return true;
}

void TLOverlayButton::callback(cocos2d::CCObject* sender) {
    m_bottomSprite->setColor(TLPalette::Light::primary);
    m_leftSprite->setColor(TLPalette::Light::primary);
    m_text->setColor(TLPalette::Light::text);

    m_bottomSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.4));
    m_leftSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.4));
    m_text->runAction(TLPalette::createTint(TLPalette::Dark::text, 0.4));

    m_config->m_onClick();
} 


