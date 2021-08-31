#include "ConfigToggle.hpp"

TLConfigToggle* TLConfigToggle::create(std::string label, toggleHandler onSelect) {
    auto ret = new TLConfigToggle(); 
    if (ret && ret->init(label, onSelect)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigToggle::init(std::string label, toggleHandler onSelect) {
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

    m_node = cocos2d::CCNode::create();
    m_node->addChild(m_bottomSprite);
    m_node->addChild(m_text);
    m_node->setContentSize(cocos2d::CCSizeMake(80.0, textHeight + 9));
    m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));

    m_toggle = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLConfigToggle::callback));
    std::cout <<"tt " << m_toggle << std::endl;

    m_callback = onSelect;

    setContentSize(m_node->getContentSize());
    return true;
}

void TLConfigToggle::callback(cocos2d::CCObject* sender) {
    std::cout <<"tc " << sender << std::endl;
    std::cout <<"tc " << reinterpret_cast<cocos2d::CCNode*>(reinterpret_cast<cocos2d::CCNode*>(sender)->getChildren()->objectAtIndex(0))->getChildrenCount() << std::endl;
    // if (g_test) {
    //     g_test->m_delegate = nullptr;
    //     g_test->onClickTrackNode(true);
    //     // g_test = nullptr;
    // }
    m_value = !m_value;
    cocos2d::CCTintTo* bottomTintTo;
    cocos2d::CCTintTo* textTintTo;
    if (m_value) {
        bottomTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::primaryLight.r, 
            TLConfigPalette::primaryLight.g, 
            TLConfigPalette::primaryLight.b);

        textTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::textLight.r, 
            TLConfigPalette::textLight.g, 
            TLConfigPalette::textLight.b);
    }
    else {
        bottomTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::primaryDark.r, 
            TLConfigPalette::primaryDark.g, 
            TLConfigPalette::primaryDark.b);

        textTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::textDark.r, 
            TLConfigPalette::textDark.g, 
            TLConfigPalette::textDark.b);
    }
    m_bottomSprite->runAction(bottomTintTo);
    m_text->runAction(textTintTo);

    m_callback(m_value);
} 

TLConfigToggle* TLConfigToggle::setValue(bool value) {
    m_value = value;
    return this;
}

TLConfigToggle* TLConfigToggle::setDefaultValue(bool value) {
    return this;
}

