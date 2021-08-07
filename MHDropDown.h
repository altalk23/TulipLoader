#pragma once
#include <Cacao.hpp>

class MHDropDown : public GJDropDownLayer {
public:
    CAC_CREATE(MHDropDown);

	virtual void customSetup();
	virtual void exitLayer(cocos2d::CCObject*);
	virtual bool init();

	void onOptions(cocos2d::CCObject*);
	void onAbout(cocos2d::CCObject*);

	CCNode* m_div;
};
