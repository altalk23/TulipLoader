#include "ExtConfigCategory.hpp"

void TLExtConfigBase::setLabel(std::string label) {
    m_label = label;
}

void TLExtConfigToggle::setDefaultValue(bool value) {
    m_defaultValue = value;
}

void TLExtConfigTextbox::setDefaultValue(std::string value) {
    m_defaultValue = value;
}

void TLExtConfigRadio::setDefaultValue(int value) {
    m_defaultValue = value;
}

TLExtConfigToggle* TLExtConfigCategory::addToggle(std::string label, toggleHandler onSelect) {
    auto item = new TLExtConfigToggle();
    item->m_label = label;
    item->m_onSelect = onSelect;
    m_items.push_back(item);
    return item;
}

TLExtConfigButton* TLExtConfigCategory::addButton(std::string label, buttonHandler onClick) {
    auto item = new TLExtConfigButton();
    item->m_label = label;
    item->m_onClick = onClick;
    m_items.push_back(item);
    return item;
}

TLExtConfigTextbox* TLExtConfigCategory::addTextbox(std::string label, textboxHandler onConfirm) {
    auto item = new TLExtConfigTextbox();
    item->m_label = label;
    item->m_onConfirm = onConfirm;
    m_items.push_back(item);
    return item;
}

TLExtConfigRadio* TLExtConfigCategory::addRadio(std::vector<std::string> labels, radioHandler onSelect) {
    auto item = new TLExtConfigRadio();
    item->m_labels = labels;
    item->m_onSelect = onSelect;
    m_items.push_back(item);
    return item;
}

TLExtConfigLabel* TLExtConfigCategory::addLabel(std::string label) {
    auto item = new TLExtConfigLabel();
    item->m_label = label;
    m_items.push_back(item);
    return item;
}

