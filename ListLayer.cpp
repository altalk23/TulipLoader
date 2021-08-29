#include "ListLayer.hpp"

TLListLayer* TLListLayer::create(cocos2d::CCArray* data) {
	auto ret = new TLListLayer(); 
    if (ret && ret->init(data)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool TLListLayer::init(cocos2d::CCArray* data) {
	CAC_TYPEINFO(0x639900);
	return BoomListView::init(data, 220.0,356.0,0,(BoomListType)0x4);
}

TableViewCell* TLListLayer::getListCell(char const* identifier) {
	// std::cout << "getListCell: "<< std::endl;
	auto cell = new TLModCell(identifier, m_height, 80.0);
	return reinterpret_cast<TableViewCell*>(cell);
}

void TLListLayer::loadCell(TableViewCell* cell, int idx) {
	// std::cout << "loadCell: "<< std::endl;
	if (idx < m_content->count()) {
		auto modInfo = reinterpret_cast<TLModInfo*>(m_content->objectAtIndex(idx));

		auto c = reinterpret_cast<TLModCell*>(cell);
    	c->loadFromObject(modInfo); 
    	c->updateBGColor(idx);
	}
	
}

void TLListLayer::setupList() {
    m_cellHeight = 80.0;
    m_tableView->reloadData();
    // std::cout << "rel" << std::endl;

    float f;
    if (m_content) f = m_content->count() * 0.5 - 1.0;
    else f = 1.0;
    m_tableView->_unknown() = f;
    // std::cout << m_tableView->_unknown() << std::endl;


    if (m_content && m_content->count() == 1) {
    	// std::cout << "moveToTopWithOffset: " << std::endl;
    	m_tableView->moveToTopWithOffset(m_cellHeight);
    }
    else {
    	// std::cout << "moveToTop: " << std::endl;
    	m_tableView->moveToTop();
    }

}
