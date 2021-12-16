#include "Radio.hpp"

TLOverlayRadio* TLOverlayRadio::create(TLRadioConfig* config) {
    auto ret = new TLOverlayRadio(); 
    if (ret && ret->init(config)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayRadio::init(TLRadioConfig* config) {
	auto label = config->m_label;
	auto labels = config->m_labels;
	m_config = config;

    auto tagIndex = 0;
    for (auto label : labels) {
        auto m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
        m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
        m_text->setPosition(cocos2d::CCPoint(nodePadding + textHorizontalPadding, 0));
        m_text->setScale(textScale);
        m_text->setContentSize(textSize);
        m_text->setColor(TLPalette::Dark::text);
        m_text->limitLabelWidth(textWidth, textScale, 0);
        m_text->setTag(3);

        auto m_leftSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
        m_leftSprite->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
        m_leftSprite->setPosition(cocos2d::CCPoint(nodePadding, verticalSpriteInset));
        m_leftSprite->setScale(spriteScale);
        m_leftSprite->setContentSize(verticalSpriteInsetSize);
        m_leftSprite->setColor(TLPalette::Dark::primary);
        m_leftSprite->setOpacity(255);
        m_leftSprite->setTag(2);

        auto m_node = cocos2d::CCNode::create();
        m_node->addChild(m_leftSprite);
        m_node->addChild(m_text);
        m_node->setContentSize(nodeSize);
        m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
        m_node->setTag(1);
        

        auto m_option = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLOverlayRadio::callback));
        m_option->setTag(++tagIndex);

        m_options.push_back(m_option);
    }
    setContentSize(cocos2d::CCSizeMake(80, tagIndex * 8 + nodePadding));

    switchColor();
    return true;
}

void TLOverlayRadio::callback(cocos2d::CCObject* sender) {
    if (sender->getTag() == value()) return;

    value() = sender->getTag();

    fadeColor();

    m_config->m_onSelect(value());
} 

int& TLOverlayRadio::value() {
    return m_config->m_value;
}

void TLOverlayRadio::fadeColor() {
	for (auto& deselected : m_options) {
        auto oldSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(deselected->getChildByTag(1)->getChildByTag(2));
        auto oldText = reinterpret_cast<cocos2d::CCLabelBMFont*>(deselected->getChildByTag(1)->getChildByTag(3));

        oldSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.1));
        oldText->runAction(TLPalette::createTint(TLPalette::Dark::text, 0.1));
    }
    if (value() > 0) {
	    auto selected = m_options[value()-1];
	    auto newSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(selected->getChildByTag(1)->getChildByTag(2));
	    auto newText = reinterpret_cast<cocos2d::CCLabelBMFont*>(selected->getChildByTag(1)->getChildByTag(3));

	    newSprite->runAction(TLPalette::createTint(TLPalette::Light::primary, 0.1));
	    newText->runAction(TLPalette::createTint(TLPalette::Light::text, 0.1));
    }
}

void TLOverlayRadio::switchColor() {
	for (auto& deselected : m_options) {
        auto oldSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(deselected->getChildByTag(1)->getChildByTag(2));
        auto oldText = reinterpret_cast<cocos2d::CCLabelBMFont*>(deselected->getChildByTag(1)->getChildByTag(3));

        oldSprite->setColor(TLPalette::Dark::primary);
        oldText->setColor(TLPalette::Dark::text);
    }
    if (value() > 0) {
	    auto selected = m_options[value()-1];
	    auto newSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(selected->getChildByTag(1)->getChildByTag(2));
	    auto newText = reinterpret_cast<cocos2d::CCLabelBMFont*>(selected->getChildByTag(1)->getChildByTag(3));

	    newSprite->setColor(TLPalette::Light::primary);
    	newText->setColor(TLPalette::Light::text);
    }
}
