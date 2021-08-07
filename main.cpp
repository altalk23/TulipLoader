#define CAC_PROJ_NAME "Megahack uwu"
#include <CacKit>
#include <iostream>
// #include "innerworkings/MacDylib.h"
// #include "MHManager.h"
#include "MHDropDown.h"

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


class MHListLayer : public BoomListView {
public:
    static MHListLayer* create(cocos2d::CCArray* p0) {
    	auto pRet = new MHListLayer(); 
	    if (pRet && pRet->init(p0)) {
	        pRet->autorelease();
	        return pRet;
	    }
	    CC_SAFE_DELETE(pRet);
	    return NULL;
    }

    bool init(cocos2d::CCArray* p0) {
    	CAC_TYPEINFO(0x639900);
    	return BoomListView::init(p0, 220.0,340.0,0,(BoomListType)0x14);
    }

    TableViewCell* getListCell(char const* p0) override {
    	std::cout << "getListCell: "<< std::endl;
    	auto cell = new ArtistCell(p0, m_height, 40.0);
    	return reinterpret_cast<TableViewCell*>(cell);
    }

    void loadCell(TableViewCell* cell, int idx) override {
    	std::cout << "loadCell: "<< std::endl;
    	if (idx < m_content->count()) {
    		auto songInfo = reinterpret_cast<SongInfoObject*>(m_content->objectAtIndex(idx));
    		auto c = reinterpret_cast<ArtistCell*>(cell);
	    	c->loadFromObject(songInfo); 
	    	c->updateBGColor(idx);
    	}
    	
    }

    void setupList() override {
    	m_cellHeight = 40.0;
    	m_tableView->reloadData();
    	std::cout << "rel" << std::endl;
    	
    	float f;
    	if (m_content) f = m_content->count() * 0.5 - 1.0;
    	else f = 1.0;
    	m_tableView->_unknown() = f;
    	std::cout << m_tableView->_unknown() << std::endl;


    	if (m_content && m_content->count() == 1) {
    		std::cout << "moveToTopWithOffset: " << std::endl;
    		m_tableView->moveToTopWithOffset(m_cellHeight);
    	}
    	else {
    		std::cout << "moveToTop: " << std::endl;
    		m_tableView->moveToTop();
    	}

    }
};



class $redirect(MenuLayer) {
public:
    void onMoreGames(CCObject* sender) {
        auto drop = MHDropDown::create();
        // drop->show();
        cac_this->addChild(drop,999);
        drop->showLayer(false);
    }
} MenuLayerHook;

class $redirect(CustomListView) {
public:
	static CustomListView* create(cocos2d::CCArray* p0, float p1, float p2, int p3, BoomListType p4) {
		std::cout << "list create" << std::endl;
		for (auto a : Cacao::ccToVec<cocos2d::CCObject*>(p0)) {
			std::cout << Cacao::typeinfo_name_for(a) << std::endl;
		}
		std::cout << p1 << " " << p2 << " " << p3 << " " << (int)p4 << " " << endl;
		return $CustomListView::create(p0, p1, p2, p3, p4);
	}
} CustomListViewHook;

class $redirect(TopArtistsLayer) {
public:
	void setupLeaderboard(cocos2d::CCArray* p0) {
		if (_commentLayer()) {
			_commentLayer()->removeMeAndCleanup();
			_commentLayer() = nullptr;
		}
		
		std::cout << "list setupLeaderboard: " << p0 << std::endl;
		if (p0) for (auto a : Cacao::ccToVec<cocos2d::CCObject*>(p0)) {
			std::cout << Cacao::typeinfo_name_for(a) << std::endl;
		}
		// return $TopArtistsLayer::setupLeaderboard(p0);
		BoomListView* list = nullptr;
		if (p0) list = MHListLayer::create(p0); 
		_commentLayer() = GJCommentListLayer::create(list, "", cocos2d::ccc4(0xbf, 0x72, 0x3e, 0xff), 340.0, 220.0, true);
		_unknown()->addChild(_commentLayer());
		auto window = cocos2d::CCDirector::sharedDirector()->getWinSize();
		_commentLayer()->setPosition(cocos2d::CCPoint((window.width - 340.0) * 0.5, (window.height - 220.0) * 0.5 + -10.0));
	}
} TopArtistsLayerHook;

$apply();
