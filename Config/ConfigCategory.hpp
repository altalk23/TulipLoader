#pragma once
#include <Cacao>

typedef void (*toggleHandler)(bool);
typedef void (*buttonHandler)();
typedef void (*textboxHandler)(std::string);
typedef void (*radioHandler)(int);

class TLConfigBase {
public:
    std::string m_label;
    virtual void setLabel(std::string label);
};

class TLToggleConfig : public TLConfigBase {
public:
    toggleHandler m_onSelect; 
    bool m_value;
    virtual void setValue(bool value);
};

class TLButtonConfig : public TLConfigBase {
public:
    buttonHandler m_onClick;
};

class TLTextboxConfig : public TLConfigBase {
public:
    textboxHandler m_onConfirm;
    std::string m_value;
    virtual void setValue(std::string value);
};

class TLRadioConfig : public TLConfigBase {
public:
    std::vector<std::string> m_labels; 
    radioHandler m_onSelect;
    int m_value;
    virtual void setValue(int value);
};

class TLLabelConfig : public TLConfigBase {};

class TLCategoryConfig {
public:
    std::vector<TLConfigBase*> m_items;

    virtual TLToggleConfig* addToggle(std::string label, toggleHandler onSelect);
    virtual TLButtonConfig* addButton(std::string label, buttonHandler onClick);
    virtual TLTextboxConfig* addTextbox(std::string label, textboxHandler onConfirm);
    virtual TLRadioConfig* addRadio(std::vector<std::string> labels, radioHandler onSelect);
    virtual TLLabelConfig* addLabel(std::string label);

};
