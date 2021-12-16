#pragma once
#include <Cacao>
#include <Manager.hpp>
#include <ModInfo.hpp>
#include <ListLayer.hpp>

using cocos2d::SEL_MenuHandler;

class TLModLayer : public GJDropDownLayer {
public:
    int m_page;
    CCMenuItemSpriteExtra* m_prevArrow;
    CCMenuItemSpriteExtra* m_nextArrow;
    cocos2d::CCLabelBMFont* m_pageLabel;
    cocos2d::CCArray* m_mods;

    static TLModLayer* create();
    virtual bool init();
    virtual void customSetup();
    virtual ~TLModLayer();

    void onNextPage(cocos2d::CCObject*);
    void onPrevPage(cocos2d::CCObject*);
    void loadPage(int page);
    void setupModBrowser(cocos2d::CCArray* data);
    void setupPageInfo(int total, int itemBegin, int itemCount);
};
