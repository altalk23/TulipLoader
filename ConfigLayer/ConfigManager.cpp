#include "ConfigManager.hpp"

TLConfigManager* TLConfigManager::sharedManager() {
    if (!g_sharedManager) {
        auto ret = g_sharedManager = new TLConfigManager();
    }
    return g_sharedManager;
}

TLExtConfigCategory* TLConfigManager::getCategory(std::string name) {
    if (g_categories.find(name) == g_categories.end()) g_categories[name] = new TLExtConfigCategory();
    return g_categories[name];  
}

std::map<std::string, TLExtConfigCategory*> TLConfigManager::getAllCategories() {
    return g_categories;  
}
