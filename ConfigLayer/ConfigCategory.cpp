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

TLConfigToggle* TLConfigCategory::addToggle(std::string label, SEL_MenuHandler onSelect) {
    auto toggle = TLConfigToggle::create(label, onSelect);
    // addChild(toggle, 1);

    toggle->m_toggler->setAnchorPoint(cocos2d::CCPoint(0.5, 0.5));


    toggle->m_toggler->setPosition(cocos2d::CCPoint(getPositionX(), getPositionY() - m_backdrop->getContentSize().height - 5));

    m_backdrop->increaseBackdrop(toggle->getContentSize().height);

    // std::cout << label << " " << *(void**)&onSelect << std::endl;

    m_parent->m_buttonMenu->addChild(toggle->m_toggler);

    return toggle;
}

void TLConfigCategory::setupItems() {
    for (auto& item : m_category->m_items) {
        if (dynamic_cast<TLExtConfigToggle*>(item)) {
            auto toggle = reinterpret_cast<TLExtConfigToggle*>(item);
            addToggle(toggle->m_label, toggle->m_onSelect)->setDefaultValue(toggle->m_defaultValue);
        }
    }
}
