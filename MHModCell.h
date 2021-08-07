#pragma once
#include <Cacao.hpp>
#include "MHModInfo.h"

class MHModCell : public TableViewCell {
public:
    MHModInfo* m_info;
    MHModCell(char const* identifier, float parentHeight, float height);
    void loadFromObject(MHModInfo* info); 
    void updateBGColor(int idx);
};
