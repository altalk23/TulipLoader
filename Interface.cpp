#include "Interface.hpp"

void TLInterface::registerMod(ModContainer* mod) {
    auto uuid = createModUUID(mod);
    if (!TLManager::sharedManager()->modExists(uuid)) {
        TLManager::sharedManager()->registerMod(uuid, mod);
    }
}

TLCategoryConfig* TLInterface::registerCategory(std::string name) {
    return TLConfigManager::sharedManager()->getCategory(name);
}
