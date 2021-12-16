#pragma once
#include <vector>
#include <map>
#include <Cacao>
#include <dlfcn.h>
#include <stdlib.h>
#include <ModHasher.hpp>
#include <FileTraversal.h>

class TLManager {
    public:
    static TLManager* sharedManager();
    void loadConfig();
    void loadMods();

    bool modExists(ModUUID uuid);
    void registerMod(ModUUID uuid, ModContainer* mod);
    void injectMod(char const* path);

    static inline TLManager* g_sharedManager = 0;
    std::map<ModUUID, ModContainer*, ModComparer> m_mods;
    std::vector<std::string> m_searchPaths;

    std::vector<ModContainer*> m_pinned;
};
