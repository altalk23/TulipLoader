#pragma once
#include <Cacao>

#include <OverlayLayer.hpp>
#include <ConfigCategory.hpp>

#include <Constant.hpp>
#include <Palette.hpp>


#include <Item/Backdrop.hpp>
#include <Item/Toggle.hpp>
#include <Item/Button.hpp>
#include <Item/Textbox.hpp>
#include <Item/Radio.hpp>
// #include <Item/Label.hpp>

using cocos2d::SEL_MenuHandler;

typedef void (*toggleHandler)(bool);
typedef void (*buttonHandler)();
typedef void (*textboxHandler)(std::string);
typedef void (*radioHandler)(int);

class TLOverlayLayer;
class TLOverlayToggle;

class TLOverlayCategory : public cocos2d::CCNode {
public:
    static TLOverlayCategory* create(std::string name, TLCategoryConfig* config, TLOverlayLayer* parent);
    bool init(std::string name, TLCategoryConfig* config, TLOverlayLayer* parent);

    void setupItems();

    TLOverlayLayer* m_parent;
    TLCategoryConfig* m_config;
    TLOverlayBackdrop* m_backdrop;

    TLOverlayToggle* addToggle(TLToggleConfig* config);
    TLOverlayButton* addButton(TLButtonConfig* config);
    TLOverlayTextbox* addTextbox(TLTextboxConfig* config);
    TLOverlayRadio* addRadio(TLRadioConfig* config);

    // virtual TLLabelConfig* addLabel(std::string label);
};
