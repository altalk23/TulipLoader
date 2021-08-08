#include "MHInterface.h"

void MHInterface::registerMod(ModContainer* mod) {
	auto uuid = createModUUID(mod);
	if (!MHManager::sharedManager()->modExists(uuid)) {
        MHManager::sharedManager()->registerMod(uuid, mod);
    }
}
