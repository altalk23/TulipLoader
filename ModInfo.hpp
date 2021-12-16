#pragma once
#include <Cacao>
#include <ModHasher.hpp>

class TLModInfo : public cocos2d::CCObject {
public:
    ModUUID m_uuid;
    ModContainer* m_container;
    TLModInfo(ModUUID uuid, ModContainer* container) {
        m_uuid = uuid;
        m_container = container;
    }
};
