#pragma once
#include <Cacao.hpp>

typedef void (*toggleHandler)(bool);
typedef void (*buttonHandler)();
typedef void (*textboxHandler)(std::string);
typedef void (*radioHandler)(int);

class TLExtConfigBase {
public:
    std::string m_label;
    virtual void setLabel(std::string label);
};

class TLExtConfigToggle : public TLExtConfigBase {
public:
    toggleHandler m_onSelect; 
    bool m_defaultValue;
    virtual void setDefaultValue(bool value);
};

class TLExtConfigButton : public TLExtConfigBase {
public:
    buttonHandler m_onClick;
};

class TLExtConfigTextbox : public TLExtConfigBase {
public:
    textboxHandler m_onConfirm;
    std::string m_defaultValue;
    virtual void setDefaultValue(std::string value);
};

class TLExtConfigRadio : public TLExtConfigBase {
public:
    std::vector<std::string> m_labels; 
    radioHandler m_onSelect;
    int m_defaultValue;
    virtual void setDefaultValue(int value);
};

class TLExtConfigLabel : public TLExtConfigBase {};

class TLExtConfigCategory {
public:
    std::vector<TLExtConfigBase*> m_items;

    virtual TLExtConfigToggle* addToggle(std::string label, toggleHandler onSelect);
    virtual TLExtConfigButton* addButton(std::string label, buttonHandler onClick);
    virtual TLExtConfigTextbox* addTextbox(std::string label, textboxHandler onConfirm);
    virtual TLExtConfigRadio* addRadio(std::vector<std::string> labels, radioHandler onSelect);
    virtual TLExtConfigLabel* addLabel(std::string label);

};
