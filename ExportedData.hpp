#pragma once

#include "ModHasher.hpp"

class TLExportedData {
public:
    static TLExportedData* sharedData();
    void saveData();
protected:
    static inline TLExportedData* g_sharedExportedData = 0;
    std::vector<ModUUID> m_pinned;
    std::vector<char const*> m_searchPaths;
};
