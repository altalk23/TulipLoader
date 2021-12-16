#include "Category.hpp"

TLOverlayCategory* TLOverlayCategory::create(std::string label, TLCategoryConfig* config, TLOverlayLayer* parent) {
    auto ret = new TLOverlayCategory(); 
    if (ret && ret->init(label, config, parent)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLOverlayCategory::init(std::string label, TLCategoryConfig* config, TLOverlayLayer* parent) {
    m_backdrop = TLOverlayBackdrop::create(label);
    addChild(m_backdrop, -2);
    m_parent = parent;
    m_config = config;
    return true;
}

TLOverlayToggle* TLOverlayCategory::addToggle(TLToggleConfig* config) {
    auto toggle = TLOverlayToggle::create(config);
    toggle->retain();

    toggle->m_toggle->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    toggle->m_toggle->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConstant::nodePadding));

    
    m_parent->m_buttonMenu->addChild(toggle->m_toggle);

    m_backdrop->increaseBackdrop(toggle->getContentSize().height);
    return toggle;
}

TLOverlayButton* TLOverlayCategory::addButton(TLButtonConfig* config) {
    auto button = TLOverlayButton::create(config);
    button->retain();

    button->m_button->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    button->m_button->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConstant::nodePadding));

    
    m_parent->m_buttonMenu->addChild(button->m_button);

    m_backdrop->increaseBackdrop(button->getContentSize().height);
    return button;
}

TLOverlayTextbox* TLOverlayCategory::addTextbox(TLTextboxConfig* config) {
    auto textbox = TLOverlayTextbox::create(config);
    textbox->retain();

    textbox->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
    textbox->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 2*TLConstant::nodePadding));

    
    m_parent->m_mainLayer->addChild(textbox, 2);

    m_backdrop->increaseBackdrop(textbox->getContentSize().height);
    return textbox;
}

TLOverlayRadio* TLOverlayCategory::addRadio(TLRadioConfig* config) {
    auto radio = TLOverlayRadio::create(config);
    radio->retain();

    for (auto option : radio->m_options) {
        option->setAnchorPoint(cocos2d::CCPoint(0.5, 0));
        option->setPosition(
        	cocos2d::CCPoint(getPositionX(), 
        		getPositionY() - 
        		m_backdrop->getContentSize().height - 2 * TLConstant::nodePadding - 
        		(option->getTag() - 1) * TLConstant::textHeight + 2
        	)
        ); //i ask why too
        m_parent->m_buttonMenu->addChild(option);
    }

    m_backdrop->increaseBackdrop(radio->getContentSize().height);
    return radio;
}


void TLOverlayCategory::setupItems() {
    for (auto& item : m_config->m_items) {
        if (auto toggle = dynamic_cast<TLToggleConfig*>(item)) {
            addToggle(toggle);
        }
        if (auto button = dynamic_cast<TLButtonConfig*>(item)) {
            addButton(button);
        }
        if (auto textbox = dynamic_cast<TLTextboxConfig*>(item)) {
            addTextbox(textbox);
        }
        if (auto radio = dynamic_cast<TLRadioConfig*>(item)) {
            addRadio(radio);
        }
    }
}
