#pragma once
#include <Cacao.hpp>
#include "ModCell.hpp"

class TLListLayer : public BoomListView {
public:
    static TLListLayer* create(cocos2d::CCArray* data);
    bool init(cocos2d::CCArray* data);
    virtual TableViewCell* getListCell(char const* identifier);
    virtual void loadCell(TableViewCell* cell, int idx);
    virtual void setupList();
};
