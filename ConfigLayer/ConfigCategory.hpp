#pragma once
#include <Cacao.hpp>

#include "ConfigOverlay.hpp"
#include "ExtConfigCategory.hpp"

#include "Item/ConfigBackdrop.hpp"
#include "Item/ConfigToggle.hpp"
// #include "Item/ConfigButton.hpp"
// #include "Item/ConfigTextbox.hpp"
// #include "Item/ConfigRadio.hpp"
// #include "Item/ConfigLabel.hpp"

using cocos2d::SEL_MenuHandler;
typedef void (cocos2d::CCObject::* SEL_RadioHandler)(cocos2d::CCObject*, int);

class TLConfigOverlay;

class TLConfigCategory : public cocos2d::CCNode {
public:
    static TLConfigCategory* create(std::string name, TLExtConfigCategory* category, TLConfigOverlay* parent);
    bool init(std::string name, TLExtConfigCategory* category, TLConfigOverlay* parent);

    void setupItems();

    TLConfigToggle* addToggle(std::string label, SEL_MenuHandler onSelect);

    TLConfigOverlay* m_parent;
    TLExtConfigCategory* m_category;
    TLConfigBackdrop* m_backdrop;


    // cocos2d::CCArray* m_items;

    // virtual TLConfigButton* addButton(std::string label, SEL_MenuHandler onClick);

    // virtual TLConfigTextbox* addTextbox(std::string label, SEL_MenuHandler onConfirm);

    // virtual TLConfigRadio* addRadio(std::string label, std::vector<std::string> options, SEL_RadioHandler onSelect);

    // virtual TLConfigLabel* addLabel(std::string label);
};
