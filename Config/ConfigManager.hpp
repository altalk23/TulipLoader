#pragma once
#include <Cacao>
#include <toml.h>

#include <ConfigCategory.hpp>


class TLConfigManager : public cocos2d::CCNode {
public:
    static TLConfigManager* sharedManager();

    static inline TLConfigManager* g_sharedManager = 0;

    std::map<std::string, TLCategoryConfig*> m_categories;

    TLCategoryConfig* getCategory(std::string name);

    std::map<std::string, TLCategoryConfig*> getAllCategories();

    void loadConfig();

    void saveConfig();
};

