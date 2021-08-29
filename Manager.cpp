#include "Manager.hpp"


TLManager* TLManager::sharedManager() {
    if (!g_sharedManager) {
        auto ret = g_sharedManager = new TLManager();
        ret->loadConfig();
        ret->loadMods();
    }
    return g_sharedManager;
}

bool TLManager::modExists(ModUUID uuid) {
    return m_mods.find(uuid) != m_mods.end();
}

void TLManager::registerMod(ModUUID uuid, ModContainer* mod) {
    std::cout << "registered mod named " << mod->getName() << std::endl;
    mod->enable();
    m_mods[uuid] = mod;
}

void TLManager::injectMod(char const* path) {
    std::cout << "injected mod at " << path << std::endl;
    void *dylib = dlopen(path, RTLD_NOW);
}

void TLManager::loadConfig() {
    m_searchPaths.push_back(std::string(getenv("HOME")) + std::string("/Documents/TLMods"));
    // TODO: actually do this
}

void TLManager::loadMods() {
    const char* paths[m_searchPaths.size()];
    size_t c = 0;
    for (auto& sp : m_searchPaths) paths[c++] = sp.c_str();

    traverse_directories(paths, m_searchPaths.size(), +[](char const* path) {
        TLManager::sharedManager()->injectMod(path);
    });
}
