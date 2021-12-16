#include "ConfigManager.hpp"

TLConfigManager* TLConfigManager::sharedManager() {
    if (!g_sharedManager) {
        auto ret = g_sharedManager = new TLConfigManager();
    }
    return g_sharedManager;
}

TLCategoryConfig* TLConfigManager::getCategory(std::string name) {
    if (m_categories.find(name) == m_categories.end()) m_categories[name] = new TLCategoryConfig();
    return m_categories[name];  
}

std::map<std::string, TLCategoryConfig*> TLConfigManager::getAllCategories() {
    return m_categories;  
}
