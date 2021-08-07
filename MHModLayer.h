#pragma once
#include <Cacao.hpp>
#include "innerworkings/MacDylib.h"
#include "MHManager.h"
#include "MHModInfo.h"
#include "MHListLayer.h"

using cocos2d::SEL_MenuHandler;

class MHModLayer : public GJDropDownLayer {
public:
    int m_page;
    CCMenuItemSpriteExtra* m_prevArrow;
    CCMenuItemSpriteExtra* m_nextArrow;
    cocos2d::CCLabelBMFont* m_pageLabel;
    cocos2d::CCArray* m_mods;

    static MHModLayer* create();
    virtual bool init();
    virtual void customSetup();

    void onNextPage(cocos2d::CCObject*);
    void onPrevPage(cocos2d::CCObject*);
    void loadPage(int page);
    void setupModBrowser(cocos2d::CCArray* data);
    void setupPageInfo(int total, int itemBegin, int itemCount);
};
