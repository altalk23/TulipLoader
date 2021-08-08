#include <stdlib.h>
#include "MHManager.h"
#include "innerworkings/filestuff.h"

MHManager* MHManager::sharedManager() {
    if (!MHManager::g_sharedManager) {
        auto ret = MHManager::g_sharedManager = new MHManager();
        ret->loadConfig();
        ret->refresh();
    }
    return MHManager::g_sharedManager;
}

void MHManager::callback(std::string path) {
    std::cout << path << std::endl;
    auto vec = loadDylib(path.c_str());
    for (auto& i : vec) {
        ModUUID uuid = createModUUID(i);
        if (m_mods.find(uuid) == m_mods.end()) {
            m_mods[uuid] = i;
        }
    }
}

bool MHManager::modExists(ModUUID uuid) {
    return m_mods.find(uuid) != m_mods.end();
}

void MHManager::registerMod(ModUUID uuid, ModContainer* mod) {
    m_mods[uuid] = mod;
}


void MHManager::loadConfig() {
    m_searchPaths.push_back(std::string(getenv("HOME")) + std::string("/Documents/examplemods"));
    // TODO: actually do this
}

void MHManager::refresh() {
    const char* ok[m_searchPaths.size()];
    size_t c = 0;
    for (auto& sp : m_searchPaths) {
        ok[c] = sp.c_str();
        c++;
    }
    traverse_directories(ok, m_searchPaths.size(), +[](char const* path) {
        MHManager::sharedManager()->callback(std::string(path));
    });
}
