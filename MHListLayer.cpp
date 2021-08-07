#pragma once
#include <Cacao.hpp>

class MHListLayer : public BoomListLayer {
public:
    static MHListLayer* create() {
    	auto pRet = new MHListLayer(); 
	    if (pRet && pRet->init()) {
	        pRet->autorelease();
	        return pRet;
	    }
	    CC_SAFE_DELETE(pRet);
	    return NULL;
    }

    TableViewCell* getListCell(char const* p0) override {
    	std::cout << "getListCell: " << p0 << std::endl;
    	return new ArtistCell(p0, m_height, 40.0)
    }

    void loadCell(TableViewCell* cell, int idx) override {
    	std::cout << "loadCell: " << idx << std::endl;
    	auto songInfo = reinterpret_cast<SongInfoObject*>(m_content->objectAtIndex(idx))
    	cell->loadFromObject(songInfo);
    	cell->updateBGColor(idx);
    }

    void setupList() override {
    	m_cellHeight = 40.0;
    	m_tableView->reloadData();
    	float f;
    	if (m_content) f = m_content->count() * 0.5 - 1.0;
    	else f = 1.0;
    	m_tableView->_unknown() = f;

    	if (m_content && m_content->count() == 1) {
    		m_tableView->moveToTopWithOffset(m_cellHeight);
    	}
    	else {
    		m_tableView->moveToTop();
    	}

    }
};
