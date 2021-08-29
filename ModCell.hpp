#pragma once
#include <Cacao.hpp>
#include "ModInfo.hpp"

class TLModCell : public TableViewCell {
public:
    TLModInfo* m_info;
    TLModCell(char const* identifier, float parentHeight, float height);
    void loadFromObject(TLModInfo* info); 
    void updateBGColor(int idx);
};
