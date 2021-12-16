#include "Textbox.hpp"

TLOverlayTextbox* TLOverlayTextbox::create(TLTextboxConfig* config) {
    auto ret = new TLOverlayTextbox(); 
    if (ret && ret->init(config)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayTextbox::init(TLTextboxConfig* config) {
	auto label = config->m_label;
	m_config = config;

    m_textbox = CCTextInputNode::create(nodeWidth, verticalSpriteLength, label.c_str(), "Thonburi", 8, "chatFont.fnt");
    m_textbox->setMaxLabelScale(textScale);
    m_textbox->setMaxLabelWidth(textWidth);
    m_textbox->setPosition(cocos2d::CCPoint(nodeWidth / 2, verticalSpriteLength / 2));
    m_textbox->setUserObject(this);
    m_textbox->setLabelPlaceholderColor(TLPalette::Dark::text);
    m_textbox->setLabelNormalColor(TLPalette::Dark::text);
    m_textbox->m_textField->setAnchorPoint(cocos2d::CCPoint(1, 0.5));
    m_textbox->m_placeholderLabel->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_textbox->m_placeholderLabel->setPosition(cocos2d::CCPoint(-textWidth / 2, textVerticalPadding / 2));
    m_textbox->setString(value());

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_bottomSprite->setPosition(cocos2d::CCPoint(nodePadding, 0));
    m_bottomSprite->setScale(spriteScale);
    m_bottomSprite->setContentSize(horizontalSpriteSize);
    m_bottomSprite->setColor(TLPalette::Dark::primary);
    m_bottomSprite->setOpacity(255);

    m_rightSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_rightSprite->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    m_rightSprite->setPosition(cocos2d::CCPoint(nodeWidth - nodePadding, 0));
    m_rightSprite->setScale(spriteScale);
    m_rightSprite->setContentSize(verticalSpriteSize);
    m_rightSprite->setColor(TLPalette::Dark::primary);
    m_rightSprite->setOpacity(255);

    addChild(m_bottomSprite);
    addChild(m_rightSprite);
    addChild(m_textbox);
    setContentSize(nodeBottomSize);
    setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    return true;
}

void TLOverlayTextbox::callback(cocos2d::CCObject* sender) {
	value() = reinterpret_cast<CCTextInputNode*>(sender)->getString();
    m_config->m_onConfirm(value());
} 

void TLOverlayTextbox::onSelect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLPalette::Light::text);

    m_bottomSprite->runAction(TLPalette::createTint(TLPalette::Light::primary, 0.1));
    m_rightSprite->runAction(TLPalette::createTint(TLPalette::Light::primary, 0.1));
} 

void TLOverlayTextbox::onDeselect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLPalette::Dark::text);

    m_bottomSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.1));
    m_rightSprite->runAction(TLPalette::createTint(TLPalette::Dark::primary, 0.1));
} 

std::string& TLOverlayTextbox::value() {
	return m_config->m_value;
}
