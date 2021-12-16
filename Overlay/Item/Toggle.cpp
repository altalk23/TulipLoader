#include "Toggle.hpp"

TLOverlayToggle* TLOverlayToggle::create(TLToggleConfig* config) {
    auto ret = new TLOverlayToggle(); 
    if (ret && ret->init(config)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayToggle::init(TLToggleConfig* config) {
	auto label = config->m_label;
	m_config = config;

    m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_text->setPosition(cocos2d::CCPoint(nodePadding + textHorizontalPadding, textVerticalPadding));
    m_text->setScale(textScale);
    m_text->setContentSize(textSize);
    m_text->limitLabelWidth(textWidth, textScale, 0);

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setAnchorPoint(cocos2d::CCPoint(0, 0));
    m_bottomSprite->setPosition(cocos2d::CCPoint(nodePadding, 0));
    m_bottomSprite->setScale(spriteScale);
    m_bottomSprite->setContentSize(horizontalSpriteSize);
    m_bottomSprite->setOpacity(255);

    m_node = cocos2d::CCNode::create();
    m_node->addChild(m_bottomSprite);
    m_node->addChild(m_text);
    m_node->setContentSize(nodeBottomSize);
    m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    switchColor();

    m_toggle = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLOverlayToggle::callback));

    setContentSize(m_node->getContentSize());
    return true;
}

void TLOverlayToggle::callback(cocos2d::CCObject* sender) {
    value() = !value();    
    fadeColor();
    m_config->m_onSelect(value());
} 

void TLOverlayToggle::fadeColor() {
	if (value()) {
        m_bottomSprite->runAction(TLPalette::createTint(TLPalette::Light::primary, 0.1));
        m_text->runAction(TLPalette::createTint(TLPalette::Light::text, 0.1));
    }
    else {
    	m_bottomSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.1));
        m_text->runAction(TLPalette::createTint(TLPalette::Dark::text, 0.1));
        
    }
}

void TLOverlayToggle::switchColor() {
	if (value()) {
		m_bottomSprite->setColor(TLPalette::Light::primary);
        m_text->setColor(TLPalette::Light::text);
    }
    else {
        m_bottomSprite->setColor(TLPalette::Dark::primary);
        m_text->setColor(TLPalette::Dark::text);
    }
}

bool& TLOverlayToggle::value() {
    return m_config->m_value;
}
