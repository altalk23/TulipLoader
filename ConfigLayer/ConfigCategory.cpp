#include "ConfigCategory.hpp"

TLConfigCategory* TLConfigCategory::create(std::string label, TLExtConfigCategory* category, TLConfigOverlay* parent) {
    auto ret = new TLConfigCategory(); 
    if (ret && ret->init(label, category, parent)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLConfigCategory::init(std::string label, TLExtConfigCategory* category, TLConfigOverlay* parent) {
    m_backdrop = TLConfigBackdrop::create(label);
    addChild(m_backdrop, -2);
    m_parent = parent;
    m_category = category;
    return true;
}

TLConfigToggle* TLConfigCategory::addToggle(std::string label, toggleHandler onSelect) {
    auto toggle = TLConfigToggle::create(label, onSelect);
    toggle->retain();

    toggle->m_toggle->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    toggle->m_toggle->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConfigConstant::nodePadding));

    
    m_parent->m_buttonMenu->addChild(toggle->m_toggle);

    m_backdrop->increaseBackdrop(toggle->getContentSize().height);
    return toggle;
}

TLConfigButton* TLConfigCategory::addButton(std::string label, buttonHandler onClick) {
    auto button = TLConfigButton::create(label, onClick);
    button->retain();

    button->m_button->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    button->m_button->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConfigConstant::nodePadding));

    
    m_parent->m_buttonMenu->addChild(button->m_button);

    m_backdrop->increaseBackdrop(button->getContentSize().height);
    return button;
}

TLConfigTextbox* TLConfigCategory::addTextbox(std::string label, textboxHandler onConfirm) {
    auto textbox = TLConfigTextbox::create(label, onConfirm);
    textbox->retain();

    textbox->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    textbox->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConfigConstant::nodePadding));

    
    m_parent->m_mainLayer->addChild(textbox, 2);

    m_backdrop->increaseBackdrop(textbox->getContentSize().height);
    return textbox;
}

TLConfigRadio* TLConfigCategory::addRadio(std::vector<std::string> labels, radioHandler onSelect) {
    auto radio = TLConfigRadio::create(labels, onSelect);
    radio->retain();

    for (auto option : radio->m_options) {
        option->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
        option->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConfigConstant::nodePadding - option->getTag() * TLConfigConstant::textHeight + 2));
        m_parent->m_buttonMenu->addChild(option);
    }

    m_backdrop->increaseBackdrop(radio->getContentSize().height);
    return radio;
}


void TLConfigCategory::setupItems() {
    for (auto& item : m_category->m_items) {
        if (dynamic_cast<TLExtConfigToggle*>(item)) {
            auto toggle = reinterpret_cast<TLExtConfigToggle*>(item);
            addToggle(toggle->m_label, toggle->m_onSelect)->setDefaultValue(toggle->m_defaultValue);
        }
        if (dynamic_cast<TLExtConfigButton*>(item)) {
            auto button = reinterpret_cast<TLExtConfigButton*>(item);
            addButton(button->m_label, button->m_onClick);
        }
        if (dynamic_cast<TLExtConfigTextbox*>(item)) {
            auto textbox = reinterpret_cast<TLExtConfigTextbox*>(item);
            addTextbox(textbox->m_label, textbox->m_onConfirm);
        }
        if (dynamic_cast<TLExtConfigRadio*>(item)) {
            auto radio = reinterpret_cast<TLExtConfigRadio*>(item);
            addRadio(radio->m_labels, radio->m_onSelect);
        }
    }
}
