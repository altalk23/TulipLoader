#pragma once
#include <Cacao.hpp>
#include "innerworkings/ModHasher.h"

class MHModInfo : public cocos2d::CCObject {
public:
    ModUUID m_uuid;
    ModContainer* m_container;
    MHModInfo(ModUUID uuid, ModContainer* container) {
        m_uuid = uuid;
        m_container = container;
    }
};
