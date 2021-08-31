#pragma once
#include <Cacao.hpp>

#include "ConfigOverlay.hpp"
#include "ExtConfigCategory.hpp"
#include "Item/ConfigConstant.hpp"

#include "Item/ConfigBackdrop.hpp"
#include "Item/ConfigToggle.hpp"
#include "Item/ConfigButton.hpp"
#include "Item/ConfigTextbox.hpp"
#include "Item/ConfigRadio.hpp"
// #include "Item/ConfigLabel.hpp"

using cocos2d::SEL_MenuHandler;

typedef void (*toggleHandler)(bool);
typedef void (*buttonHandler)();
typedef void (*textboxHandler)(std::string);
typedef void (*radioHandler)(int);

class TLConfigOverlay;

class TLConfigCategory : public cocos2d::CCNode {
public:
    static TLConfigCategory* create(std::string name, TLExtConfigCategory* category, TLConfigOverlay* parent);
    bool init(std::string name, TLExtConfigCategory* category, TLConfigOverlay* parent);

    void setupItems();

    TLConfigOverlay* m_parent;
    TLExtConfigCategory* m_category;
    TLConfigBackdrop* m_backdrop;

    TLConfigToggle* addToggle(std::string label, toggleHandler onSelect);
    TLConfigButton* addButton(std::string label, buttonHandler onClick);
    TLConfigTextbox* addTextbox(std::string label, textboxHandler onConfirm);
    TLConfigRadio* addRadio(std::vector<std::string> labels, radioHandler onSelect);

    // virtual TLConfigLabel* addLabel(std::string label);
};
