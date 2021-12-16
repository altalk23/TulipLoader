#include "ConfigCategory.hpp"

void TLConfigBase::setLabel(std::string label) {
    m_label = label;
}

void TLToggleConfig::setValue(bool value) {
    m_value = value;
}

void TLTextboxConfig::setValue(std::string value) {
    m_value = value;
}

void TLRadioConfig::setValue(int value) {
    m_value = value;
}

TLToggleConfig* TLCategoryConfig::addToggle(std::string label, toggleHandler onSelect) {
    auto item = new TLToggleConfig();
    item->m_label = label;
    item->m_onSelect = onSelect;
    m_items.push_back(item);
    return item;
}

TLButtonConfig* TLCategoryConfig::addButton(std::string label, buttonHandler onClick) {
    auto item = new TLButtonConfig();
    item->m_label = label;
    item->m_onClick = onClick;
    m_items.push_back(item);
    return item;
}

TLTextboxConfig* TLCategoryConfig::addTextbox(std::string label, textboxHandler onConfirm) {
    auto item = new TLTextboxConfig();
    item->m_label = label;
    item->m_onConfirm = onConfirm;
    m_items.push_back(item);
    return item;
}

TLRadioConfig* TLCategoryConfig::addRadio(std::vector<std::string> labels, radioHandler onSelect) {
    auto item = new TLRadioConfig();
    item->m_labels = labels;
    item->m_onSelect = onSelect;
    m_items.push_back(item);
    return item;
}

TLLabelConfig* TLCategoryConfig::addLabel(std::string label) {
    auto item = new TLLabelConfig();
    item->m_label = label;
    m_items.push_back(item);
    return item;
}

