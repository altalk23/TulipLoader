#include "ConfigTextbox.hpp"

TLConfigTextbox* TLConfigTextbox::create(std::string label, textboxHandler onConfirm) {
    auto ret = new TLConfigTextbox(); 
    if (ret && ret->init(label, onConfirm)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigTextbox::init(std::string label, textboxHandler onConfirm) {

    m_textbox = CCTextInputNode::create(nodeWidth, verticalSpriteLength, label.c_str(), "Thonburi", 8, "chatFont.fnt");
    m_textbox->setMaxLabelScale(textScale);
    m_textbox->setMaxLabelWidth(textWidth);
    m_textbox->setPosition(cocos2d::CCPoint(nodeWidth / 2, verticalSpriteLength / 2));
    m_textbox->setUserObject(this);
    m_textbox->setLabelPlaceholderColor(TLConfigPalette::textDark);
    m_textbox->m_textField->setAnchorPoint(cocos2d::CCPoint(1, 0.5));
    m_textbox->m_placeholderLabel->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_textbox->m_placeholderLabel->setPosition(cocos2d::CCPoint(-textWidth / 2, textVerticalPadding / 2));

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_bottomSprite->setPosition(cocos2d::CCPoint(nodePadding, 0));
    m_bottomSprite->setScale(spriteScale);
    m_bottomSprite->setContentSize(horizontalSpriteSize);
    m_bottomSprite->setColor(TLConfigPalette::primaryDark);
    m_bottomSprite->setOpacity(255);

    m_rightSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_rightSprite->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    m_rightSprite->setPosition(cocos2d::CCPoint(nodeWidth - nodePadding, 0));
    m_rightSprite->setScale(spriteScale);
    m_rightSprite->setContentSize(verticalSpriteSize);
    m_rightSprite->setColor(TLConfigPalette::primaryDark);
    m_rightSprite->setOpacity(255);

    addChild(m_bottomSprite);
    addChild(m_rightSprite);
    addChild(m_textbox);
    setContentSize(nodeBottomSize);
    setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_callback = onConfirm;
    return true;
}

void TLConfigTextbox::callback(cocos2d::CCObject* sender) {
    m_callback(reinterpret_cast<CCTextInputNode*>(sender)->getString());
} 

void TLConfigTextbox::onSelect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLConfigPalette::textLight);

    m_bottomSprite->runAction(TLConfigPalette::createTint(TLConfigPalette::primaryLight, 0.1));
    m_rightSprite->runAction(TLConfigPalette::createTint(TLConfigPalette::primaryLight, 0.1));
} 

void TLConfigTextbox::onDeselect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLConfigPalette::textDark);

    m_bottomSprite->runAction(TLConfigPalette::createTint(TLConfigPalette::primaryDark, 0.1));
    m_rightSprite->runAction(TLConfigPalette::createTint(TLConfigPalette::primaryDark, 0.1));
} 


