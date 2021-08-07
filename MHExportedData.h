#pragma once

#include "ModHasher.h"

class MHExportedData {
 public:
 	static MHExportedData* sharedData();
 	void saveData();
 protected:
 	static inline MHExportedData* g_sharedExportedData = 0;
 	std::vector<ModUUID> m_pinned;
 	std::vector<char const*> m_searchPaths;
};