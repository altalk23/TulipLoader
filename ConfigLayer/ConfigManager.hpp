#pragma once
#include <Cacao.hpp>
#include "ConfigCategory.hpp"
#include "ExtConfigCategory.hpp"


class TLConfigManager : public cocos2d::CCNode {
public:
    static TLConfigManager* sharedManager();

    static inline TLConfigManager* g_sharedManager = 0;

    static inline std::map<std::string, TLExtConfigCategory*> g_categories;

    TLExtConfigCategory* getCategory(std::string name);

    std::map<std::string, TLExtConfigCategory*> getAllCategories();
};

