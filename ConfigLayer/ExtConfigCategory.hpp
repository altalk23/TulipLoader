#pragma once
#include <Cacao.hpp>

using cocos2d::SEL_MenuHandler;
typedef void (cocos2d::CCObject::* SEL_RadioHandler)(cocos2d::CCObject*, int);

class TLExtConfigBase {
public:
    std::string m_label;
    virtual void setLabel(std::string label);
};

class TLExtConfigToggle : public TLExtConfigBase {
public:
    SEL_MenuHandler m_onSelect; 
    bool m_defaultValue;
    virtual void setDefaultValue(bool value);
};

class TLExtConfigButton : public TLExtConfigBase {
public:
    SEL_MenuHandler m_onClick;
};

class TLExtConfigTextbox : public TLExtConfigBase {
public:
    SEL_MenuHandler m_onConfirm;
    std::string m_defaultValue;
    virtual void setDefaultValue(std::string value);
};

class TLExtConfigRadio : public TLExtConfigBase {
public:
    std::vector<std::string> m_options; 
    SEL_RadioHandler m_onSelect;
    int m_defaultValue;
    virtual void setDefaultValue(int value);
};

class TLExtConfigLabel : public TLExtConfigBase {};

class TLExtConfigCategory {
public:
    std::vector<TLExtConfigBase*> m_items;

    virtual TLExtConfigToggle* addToggle(std::string label, SEL_MenuHandler onSelect);
    virtual TLExtConfigButton* addButton(std::string label, SEL_MenuHandler onClick);
    virtual TLExtConfigTextbox* addTextbox(std::string label, SEL_MenuHandler onConfirm);
    virtual TLExtConfigRadio* addRadio(std::string label, std::vector<std::string> options, SEL_RadioHandler onSelect);
    virtual TLExtConfigLabel* addLabel(std::string label);

};
