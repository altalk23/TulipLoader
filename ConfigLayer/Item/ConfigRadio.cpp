#include "ConfigRadio.hpp"

TLConfigRadio* TLConfigRadio::create(std::vector<std::string> labels, radioHandler onSelect) {
    auto ret = new TLConfigRadio(); 
    if (ret && ret->init(labels, onSelect)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigRadio::init(std::vector<std::string> labels, radioHandler onSelect) {
    auto tagIndex = 0;
    for (auto label : labels) {
        auto m_text = cocos2d::CCLabelBMFont::create(label.c_str(), "chatFont.fnt");
        m_text->setAnchorPoint(cocos2d::CCPoint(0, 0));
        m_text->setPosition(cocos2d::CCPoint(8, 0));
        m_text->setContentSize(cocos2d::CCSizeMake(80, 8));
        m_text->setScale(0.4);
        m_text->limitLabelWidth(64, 0.4, 0);
        m_text->setColor(TLConfigPalette::textDark);
        m_text->setTag(3);

        auto m_leftSprite = cocos2d::extension::CCScale9Sprite::create("square.png");
        m_leftSprite->setScale(0.05);
        m_leftSprite->setContentSize(cocos2d::CCSizeMake(1 / 0.05, 7 / 0.05));
        m_leftSprite->setColor(TLConfigPalette::primaryDark);
        m_leftSprite->setOpacity(255);
        m_leftSprite->setAnchorPoint(cocos2d::CCPoint(0, 0));
        m_leftSprite->setPosition(cocos2d::CCPoint(5, 0.5));
        m_leftSprite->setTag(2);

        auto m_node = cocos2d::CCNode::create();
        m_node->addChild(m_leftSprite);
        m_node->addChild(m_text);
        m_node->setContentSize(cocos2d::CCSizeMake(80, 8));
        m_node->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
        m_node->setTag(1);
        

        auto m_option = cocos2d::CCMenuItemSprite::create(m_node, m_node, this, menu_selector(TLConfigRadio::callback));
        m_option->setTag(tagIndex++);

        m_options.push_back(m_option);
    }
    setContentSize(cocos2d::CCSizeMake(80, tagIndex * 8 + 5));
    m_callback = onSelect;
    m_value = -1;
    return true;
}

void TLConfigRadio::callback(cocos2d::CCObject* sender) {
    if (sender->getTag() == m_value) return;
    if (m_value >= 0) {
        auto deselected = m_options[m_value];
        auto oldSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(deselected->getChildByTag(1)->getChildByTag(2));
        auto oldText = reinterpret_cast<cocos2d::CCLabelBMFont*>(deselected->getChildByTag(1)->getChildByTag(3));

        auto oldSpriteTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::primaryDark.r, 
            TLConfigPalette::primaryDark.g, 
            TLConfigPalette::primaryDark.b);
 
        auto oldTextTintTo = cocos2d::CCTintTo::create(0.1, 
            TLConfigPalette::textDark.r, 
            TLConfigPalette::textDark.g, 
            TLConfigPalette::textDark.b);

        oldSprite->runAction(oldSpriteTintTo);
        oldText->runAction(oldTextTintTo);
    }

    m_value = sender->getTag();
    auto selected = m_options[m_value];
    auto newSprite = reinterpret_cast<cocos2d::extension::CCScale9Sprite*>(selected->getChildByTag(1)->getChildByTag(2));
    auto newText = reinterpret_cast<cocos2d::CCLabelBMFont*>(selected->getChildByTag(1)->getChildByTag(3));

    auto newSpriteTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::primaryLight.r, 
        TLConfigPalette::primaryLight.g, 
        TLConfigPalette::primaryLight.b);

    auto newTextTintTo = cocos2d::CCTintTo::create(0.1, 
        TLConfigPalette::textLight.r, 
        TLConfigPalette::textLight.g, 
        TLConfigPalette::textLight.b);

    newSprite->runAction(newSpriteTintTo);
    newText->runAction(newTextTintTo);

    m_callback(m_value);
} 

TLConfigRadio* TLConfigRadio::setValue(int value) {
    m_value = value;
    return this;
}

TLConfigRadio* TLConfigRadio::setDefaultValue(int value) {
    return this;
}

