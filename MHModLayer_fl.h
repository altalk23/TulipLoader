#pragma once
#include <Cacao.hpp>

class MHModLayer : public FLAlertLayer {
public:
    int m_page;
    CCMenuItemSpriteExtra* m_prevArrow;
    CCMenuItemSpriteExtra* m_nextArrow;

    MHModLayer();
    static MHModLayer* create();
    virtual void keyBackClicked();
    bool init();
    void onNextPage(cocos2d::CCObject*);
    void onPrevPage(cocos2d::CCObject*);
    void onClose(cocos2d::CCObject*);
    void loadPage(int page);
    void setupModBrowser(cocos2d::CCArray* data);
    void setupPageInfo(int total, int itemBegin, int itemCount);
};
