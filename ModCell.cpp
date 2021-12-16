#include "ModCell.hpp"

TLModCell::TLModCell(char const* identifier, float parentHeight, float height) : TableViewCell(identifier, parentHeight, height) {
    
}

void TLModCell::loadFromObject(TLModInfo* info) {
    m_info = info;
    m_mainLayer->removeAllChildrenWithCleanup(true);
    auto modNameLabel = cocos2d::CCLabelBMFont::create(m_info->m_container->getName().c_str(), "bigFont.fnt");
    modNameLabel->limitLabelWidth(200.0, 0.8, 0.0);
    modNameLabel->setAnchorPoint(cocos2d::CCPoint(0.0, 0.5));
    modNameLabel->setPosition(15.0, m_height * 0.5);
    m_mainLayer->addChild(modNameLabel);
}
    
void TLModCell::updateBGColor(int idx) {
    if (idx & 1) m_backgroundLayer->setColor(cocos2d::ccc3(0xc2, 0x72, 0x3e));
    else m_backgroundLayer->setColor(cocos2d::ccc3(0xa1, 0x58, 0x2c));
    m_backgroundLayer->setOpacity(0xff);
}
