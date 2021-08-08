#pragma once
#include <vector>
#include <map>
#include <Cacao.hpp>
#include "innerworkings/MacDylib.h"
#include "innerworkings/ModHasher.h"

class MHManager {
	public:
	static MHManager* sharedManager();
	void refresh();
	void loadConfig();
	void callback(std::string path);

	bool modExists(ModUUID uuid);
	void registerMod(ModUUID uuid, ModContainer* mod);

	static inline MHManager* g_sharedManager = 0;
	std::map<ModUUID, ModContainer*, ModComparer> m_mods;
	std::vector<std::string> m_searchPaths;

	std::vector<ModContainer*> m_pinned;
};
