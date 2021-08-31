#pragma once
#include <Cacao.hpp>

namespace TLConfigPalette {
    static cocos2d::_ccColor3B const primaryLight = cocos2d::ccc3(240, 120, 240);

    static cocos2d::_ccColor3B const primary = cocos2d::ccc3(180, 90, 180);

    static cocos2d::_ccColor3B const primaryDark = cocos2d::ccc3(120, 60, 120);

    static cocos2d::_ccColor3B const textLight = cocos2d::ccc3(240, 240, 240);

    static cocos2d::_ccColor3B const text = cocos2d::ccc3(180, 180, 180);

    static cocos2d::_ccColor3B const textDark = cocos2d::ccc3(120, 120, 120);

    static inline cocos2d::CCTintTo* createTint(cocos2d::_ccColor3B color, float duration) {
        return cocos2d::CCTintTo::create(duration, color.r, color.g, color.b);
    }
}
