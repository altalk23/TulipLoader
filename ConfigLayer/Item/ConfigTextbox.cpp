#include "ConfigTextbox.hpp"

// TLTextInputNode* TLTextInputNode::create(float p0, float p1, char const* p2, char const* p3, int p4, char const* p5) {
//     auto ret = new TLTextInputNode(); 
//     if (ret && ret->init(p0, p1, p2, p3, p4, p5)) {
//         ret->autorelease();
//         return ret;
//     }
//     CC_SAFE_DELETE(ret);
//     return NULL;
// }

// bool TLTextInputNode::init(float p0, float p1, char const* p2, char const* p3, int p4, char const* p5) {
//     CAC_TYPEINFO(0x60abd0);
//     return CCTextInputNode::init(p0, p1, p2, p3, p4, p5);
// }

template <typename F>
inline long extract(F func) {
    return (*reinterpret_cast<long*>(&func));
};

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
    CAC_TYPEINFO(0x624f70);
    // m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
    // m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
    // m_text->setPosition(cocos2d::CCPoint(8, 7));
    // m_text->setScale(0.4);
    // m_text->limitLabelWidth(64.0, 0.4, 0.0);
    // m_text->setColor(TLConfigPalette::textDark);

    // auto textHeight = m_text->getContentSize().height * m_text->getScaleY();
    m_textbox = CCTextInputNode::create(80.0, 8.0, "test", "Thonburi", 8, "chatFont.fnt");
    m_textbox->setMaxLabelScale(0.4);
    m_textbox->setMaxLabelWidth(64.0);
    m_textbox->setPosition(cocos2d::CCPoint(40, 11));
    m_textbox->setUserObject(this);
    m_textbox->setLabelPlaceholderColor(TLConfigPalette::textDark);
    m_textbox->m_textField->setAnchorPoint(cocos2d::CCPoint(1, 1.5));
    // m_textbox->m_textField->setHorizontalAlignment(cocos2d::CCTextAlignment::kCCTextAlignmentLeft);
    m_textbox->m_placeholderLabel->setAnchorPoint(cocos2d::CCPoint(0, 0.5));
    m_textbox->m_placeholderLabel->setPosition(cocos2d::CCPoint(-32, 0));

    auto textHeight = m_textbox->getContentSize().height * m_textbox->getScaleY();

    m_bottomSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_bottomSprite->setScale(0.05);
    m_bottomSprite->setContentSize(cocos2d::CCSizeMake(70.0 / 0.05, 1.0 / 0.05));
    m_bottomSprite->setColor(TLConfigPalette::primaryDark);
    m_bottomSprite->setOpacity(255);
    m_bottomSprite->setPosition(cocos2d::CCPoint(40.0, 5.0));

    m_rightSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
    m_rightSprite->setScale(0.05);
    m_rightSprite->setContentSize(cocos2d::CCSizeMake(1.0 / 0.05, (textHeight + 2) / 0.05));
    m_rightSprite->setColor(TLConfigPalette::primaryDark);
    m_rightSprite->setOpacity(255);
    m_rightSprite->setAnchorPoint(cocos2d::CCPoint(1, 0));
    m_rightSprite->setPosition(cocos2d::CCPoint(75.0, 5.0));


    addChild(m_bottomSprite);
    addChild(m_rightSprite);
    addChild(m_textbox);
    setContentSize(cocos2d::CCSizeMake(80.0, textHeight + 9));
    setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_callback = onConfirm;
    return true;
}

void TLConfigTextbox::callback(cocos2d::CCObject* sender) {
    // m_bottomSprite->setColor(TLConfigPalette::primaryLight);
    // m_leftSprite->setColor(TLConfigPalette::primaryLight);
    // m_text->setColor(TLConfigPalette::textLight);

    // auto bottomTintTo = cocos2d::CCTintTo::create(0.4, 
    //     TLConfigPalette::primaryDark.r, 
    //     TLConfigPalette::primaryDark.g, 
    //     TLConfigPalette::primaryDark.b);

    // auto leftTintTo = cocos2d::CCTintTo::create(0.4, 
    //     TLConfigPalette::primaryDark.r, 
    //     TLConfigPalette::primaryDark.g, 
    //     TLConfigPalette::primaryDark.b);

    // auto textTintTo = cocos2d::CCTintTo::create(0.4, 
    //     TLConfigPalette::textDark.r, 
    //     TLConfigPalette::textDark.g, 
    //     TLConfigPalette::textDark.b);

    // m_bottomSprite->runAction(bottomTintTo);
    // m_leftSprite->runAction(leftTintTo);
    // m_text->runAction(textTintTo);

    m_callback(reinterpret_cast<CCTextInputNode*>(sender)->getString());
} 

void TLConfigTextbox::onSelect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLConfigPalette::textLight);

    auto bottomTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::primaryLight.r, 
        TLConfigPalette::primaryLight.g, 
        TLConfigPalette::primaryLight.b);

    auto rightTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::primaryLight.r, 
        TLConfigPalette::primaryLight.g, 
        TLConfigPalette::primaryLight.b);

    m_bottomSprite->runAction(bottomTintTo);
    m_rightSprite->runAction(rightTintTo);
} 

void TLConfigTextbox::onDeselect(cocos2d::CCObject* sender) {
    m_textbox->setLabelNormalColor(TLConfigPalette::textDark);

    auto bottomTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::primaryDark.r, 
        TLConfigPalette::primaryDark.g, 
        TLConfigPalette::primaryDark.b);

    auto rightTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::primaryDark.r, 
        TLConfigPalette::primaryDark.g, 
        TLConfigPalette::primaryDark.b);

    m_bottomSprite->runAction(bottomTintTo);
    m_rightSprite->runAction(rightTintTo);
} 


