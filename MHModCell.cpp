#include "MHModCell.h"

MHModCell::MHModCell(char const* identifier, float parentHeight, float height) : TableViewCell(identifier, parentHeight, height) {
    
}

void MHModCell::loadFromObject(MHModInfo* info) {
    m_info = info;
    // std::cout << this << std::endl;
    // std::cout << info << std::endl;
    // std::cout << (char*)(&m_mainLayer) - (char*)this << std::endl;
    // std::cout << m_backgroundLayer << std::endl;
    m_mainLayer->removeAllChildrenWithCleanup(true);
    auto artistLabel = cocos2d::CCLabelBMFont::create(m_info->m_container->getName(), "bigFont.fnt");
    artistLabel->limitLabelWidth(200.0, 0.8, 0.0);
    artistLabel->setAnchorPoint(cocos2d::CCPoint(0.0, 0.5));
    artistLabel->setPosition(15.0, m_height * 0.5);
    m_mainLayer->addChild(artistLabel);
}
    
void MHModCell::updateBGColor(int idx) {
    if (idx & 1) m_backgroundLayer->setColor(cocos2d::ccc3(0xc2, 0x72, 0x3e));
    else m_backgroundLayer->setColor(cocos2d::ccc3(0xa1, 0x58, 0x2c));
    m_backgroundLayer->setOpacity(0xff);
}
