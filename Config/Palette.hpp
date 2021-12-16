#pragma once
#include <Cacao>

namespace TLPalette {
	struct Default {
		static inline cocos2d::_ccColor3B const primary = cocos2d::ccc3(180, 90, 180);
		static inline cocos2d::_ccColor3B const secondary = cocos2d::ccc3(90, 180, 180);
		static inline cocos2d::_ccColor3B const text = cocos2d::ccc3(180, 180, 180);
	};
	struct Dark {
		static inline cocos2d::_ccColor3B const primary = cocos2d::ccc3(120, 60, 120);
		static inline cocos2d::_ccColor3B const secondary = cocos2d::ccc3(60, 120, 120);
		static inline cocos2d::_ccColor3B const text = cocos2d::ccc3(120, 120, 120);
	};
	struct Light {
		static inline cocos2d::_ccColor3B const primary = cocos2d::ccc3(240, 120, 240);
		static inline cocos2d::_ccColor3B const secondary = cocos2d::ccc3(120, 240, 240);
		static inline cocos2d::_ccColor3B const text = cocos2d::ccc3(240, 240, 240);
	};

    static inline cocos2d::CCTintTo* createTint(cocos2d::_ccColor3B color, float duration) {
        return cocos2d::CCTintTo::create(duration, color.r, color.g, color.b);
    }
}
