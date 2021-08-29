#include <Cacao.hpp>
using namespace cocos2d;

class StatsObject {
    static StatsObject* create(char const*, int);
};

class StatsLayer : public GJDropDownLayer {
    static StatsLayer* create() {
        auto pRet = new StatsLayer();
        if (pRet && pRet->init("Stats")) {
            pRet->autorelease();
            return pRet;
        }
        CC_SAFE_DELETE(pRet);
        return NULL;
    }

    void customSetup() override {
        auto wSize = CCDirector::sharedDirector()->getWinSize();
        auto stats = CCArray::create();


        //just this repeated for each stat
        char const* statname = "1";
        stats->addObject(StatsObject::create(statename, GameStatsManager::sharedManager()->getStat(statname)));
        //314

        auto list = CustomListView::create(stats, 220.0, 356.0, 0, 3);
        m_mainLayer->addChild(list);
        m_mainLayer->setColor();

    }
};
