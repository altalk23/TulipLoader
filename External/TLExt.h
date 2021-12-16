#pragma once
#include <Cacao>
#include <dlfcn.h>
#include <mach-o/dyld.h>

namespace TLExt {
    class ConfigBase {
    public:
        virtual void setLabel(std::string label);
    };

    class ConfigToggle : public ConfigBase {
    public:
        virtual void setDefaultValue(bool value);

    };

    class ConfigButton : public ConfigBase {};

    class ConfigTextbox : public ConfigBase {
    public:
        virtual void setDefaultValue(std::string value);
    };

    class ConfigRadio : public ConfigBase {
    public:
        virtual void setDefaultValue(int value);
    };

    class ConfigLabel : public ConfigBase {};

    typedef void (*toggleHandler)(bool);
    typedef void (*buttonHandler)();
    typedef void (*textboxHandler)(std::string);
    typedef void (*radioHandler)(int);

    class ConfigCategory {
    public:
        virtual ConfigToggle* addToggle(std::string label, toggleHandler onSelect);
        virtual ConfigButton* addButton(std::string label, buttonHandler onClick);
        virtual ConfigTextbox* addTextbox(std::string label, textboxHandler onConfirm);
        virtual ConfigRadio* addRadio(std::string label, std::vector<std::string> options, radioHandler onSelect);
        virtual ConfigLabel* addLabel(std::string label);
    };



    typedef void(*registerModType)(ModContainer*);
    typedef ConfigCategory*(*registerCategoryType)(std::string);

    registerModType registerMod;
    registerCategoryType registerCategory;

    bool g_initialized = false;

    bool init() {
        int imageCount = _dyld_image_count();
        void* dylib = nullptr;

        for (int i = 0; i < imageCount; ++i) {
            std::string imageName = _dyld_get_image_name(i);
            if (imageName.find("libTulipLoader.dylib") != std::string::npos) {
                dylib = dlopen(_dyld_get_image_name(i), RTLD_LAZY | RTLD_NOLOAD);
                break;
            }
        }
        if (dylib == nullptr) return false;

        registerMod = reinterpret_cast<registerModType>(dlsym(dylib, "_ZN11TLInterface11registerModEP12ModContainer"));
        if (registerMod == nullptr) return false;

        registerCategory = reinterpret_cast<registerCategoryType>(dlsym(dylib, "_ZN11TLInterface16registerCategoryESs"));
        if (registerCategory == nullptr) return false;
        
        return g_initialized = true;
    }
}

#define $TLapply() void __tl_apply() {                                  \
    __if_exists(inject) {                                               \
        inject();                                                       \
    }                                                                   \
    for (auto& i : __cackit::glob) i->apply_hooks();                    \
    if (TLExt::g_initialized) {                                         \
        TLExt::registerMod(m);                                          \
    }                                                                   \
    else if (__cackit::glob.size() > 0) m->enable();                    \
}                                                                       \
static int const __tl_register = (__tl_apply(), 0)
