#define CAC_PROJ_NAME "Megahack uwu"
#include <CacKit>
#include <iostream>
// #include "innerworkings/MacDylib.h"
// #include "MHManager.h"
#include "MHListLayer.h"
#include "MHModLayer.h"

// class MHDropdown : public GJDropDownLayer {
// public:
//     CAC_CREATE(MHDropdown);

//     bool init() {
//         CAC_TYPEINFO(0x6754b0); // don't question it
//         if (GJDropDownLayer::init("Mods", 220.0)) {
//             std::cout << "size is " << MHManager::sharedManager()->m_mods.size() << "\n";
//             for (auto& i : MHManager::sharedManager()->m_mods) {
//                 std::cout << "name is " << i.second->getName() << "\n";
//             }
//         }
//         return true;
//     }
// };




class $redirect(MenuLayer) {
public:
    void onMoreGames(CCObject* sender) {
        // auto drop = MHDropDown::create();
        // cac_this->addChild(drop,999);
        // drop->showLayer(false);

        auto list = MHModLayer::create();
        addChild(list, 999);
        list->showLayer(false);
    }
} MenuLayerHook;

// class $redirect(CustomListView) {
// public:
// 	static CustomListView* create(cocos2d::CCArray* p0, float p1, float p2, int p3, BoomListType p4) {
// 		std::cout << "list create" << std::endl;
// 		for (auto a : Cacao::ccToVec<cocos2d::CCObject*>(p0)) {
// 			std::cout << Cacao::typeinfo_name_for(a) << std::endl;
// 		}
// 		std::cout << p1 << " " << p2 << " " << p3 << " " << (int)p4 << " " << endl;
// 		return $CustomListView::create(p0, p1, p2, p3, p4);
// 	}
// } CustomListViewHook;

class $redirect(TopArtistsLayer) {
public:
	void setupPageInfo(std::string p0, char const* p1) {
		// std::cout << "setupPageInfo" << std::endl;
		// std::cout << p0 << std::endl;
		// std::cout << p1 << std::endl;
		$TopArtistsLayer::setupPageInfo(p0, p1);
	}
	void setupLeaderboard(cocos2d::CCArray* p0) {
		// std::cout << " aa " << this << std::endl;
		// std::cout << " aa " << this->__member<cocos2d::CCArray*>(0x258) << std::endl;
		if (_commentLayer()) {
			_commentLayer()->removeMeAndCleanup();
			_commentLayer() = nullptr;
		}
		
		// std::cout << "list setupLeaderboard: " << p0 << std::endl;
		// if (p0) for (auto a : Cacao::ccToVec<cocos2d::CCObject*>(p0)) {
		// 	std::cout << Cacao::typeinfo_name_for(a) << std::endl;
		// }
		// return $TopArtistsLayer::setupLeaderboard(p0);
		BoomListView* list = nullptr;
		if (p0) list = MHListLayer::create(p0); 
		_commentLayer() = GJCommentListLayer::create(list, "", cocos2d::ccc4(0xbf, 0x72, 0x3e, 0xff), 340.0, 220.0, true);
		_unknown()->addChild(_commentLayer());
		auto window = cocos2d::CCDirector::sharedDirector()->getWinSize();
		_commentLayer()->setPosition(cocos2d::CCPoint((window.width - 340.0) * 0.5, (window.height - 220.0) * 0.5 + -10.0));
	}
} TopArtistsLayerHook;

// class $redirect(GameLevelManager) {
// public:
// 	cocos2d::CCArray* getStoredOnlineLevels(char const* key) {
// 		auto array = $GameLevelManager::getStoredOnlineLevels(key);
// 		// std::cout << "list getStoredOnlineLevels: " << array << " key: " << key << std::endl;
// 		if (array) {
// 			// std::cout << "size" << array->count() << std::endl;
// 			// for (auto a : Cacao::ccToVec<cocos2d::CCObject*>(array)) {
// 			// 	std::cout << Cacao::typeinfo_name_for(a) << std::endl;
// 			// }
// 		}
// 		return array;
// 	}
// } GameLevelManagerHook;



$apply();
