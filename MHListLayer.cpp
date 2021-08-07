#include "MHListLayer.h"

MHListLayer* MHListLayer::create(cocos2d::CCArray* data) {
	auto ret = new MHListLayer(); 
    if (ret && ret->init(data)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool MHListLayer::init(cocos2d::CCArray* data) {
	CAC_TYPEINFO(0x639900);
	return BoomListView::init(data, 220.0,356.0,0,(BoomListType)0x4);
}

TableViewCell* MHListLayer::getListCell(char const* identifier) {
	// std::cout << "getListCell: "<< std::endl;
	auto cell = new MHModCell(identifier, m_height, 40.0);
	return reinterpret_cast<TableViewCell*>(cell);
}

void MHListLayer::loadCell(TableViewCell* cell, int idx) {
	// std::cout << "loadCell: "<< std::endl;
	if (idx < m_content->count()) {
		auto songInfo = reinterpret_cast<MHModInfo*>(m_content->objectAtIndex(idx));
		// std::cout << songInfo->__member<int>(0x120) << std::endl;
		// std::cout << songInfo->__member<std::string>(0x128) << std::endl;
		// std::cout << songInfo->__member<std::string>(0x130) << std::endl;
		// std::cout << songInfo->__member<std::string>(0x138) << std::endl;
		// std::cout << songInfo->__member<std::string>(0x140) << std::endl;
		// std::cout << songInfo->__member<std::string>(0x148) << std::endl;
		// std::cout << songInfo->__member<int>(0x150) << std::endl;
		// std::cout << songInfo->__member<float>(0x154) << std::endl;
		// std::cout << songInfo->__member<unsigned short>(0x15a) << std::endl;
		// std::cout << songInfo->__member<int>(0x15c) << std::endl;

		auto c = reinterpret_cast<MHModCell*>(cell);
    	c->loadFromObject(songInfo); 
    	c->updateBGColor(idx);
	}
	
}

void MHListLayer::setupList() {
	m_cellHeight = 40.0;
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
