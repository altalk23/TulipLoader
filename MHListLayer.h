#pragma once
#include <Cacao.hpp>
#include "MHModCell.h"

class MHListLayer : public BoomListView {
public:
    static MHListLayer* create(cocos2d::CCArray* data);
    bool init(cocos2d::CCArray* data);
    virtual TableViewCell* getListCell(char const* identifier);
    virtual void loadCell(TableViewCell* cell, int idx);
    virtual void setupList();
};
