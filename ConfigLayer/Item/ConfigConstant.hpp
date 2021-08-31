#pragma once
#include <Cacao.hpp>

namespace TLConfigConstant {
    static float const textVerticalPadding = 2.0;
    static float const textHorizontalPadding = 3.0;
    static float const nodePadding = 5.0;

    static float const textWidth = 64.0;
    static float const textHeight = 8.0;

    static float const titleTextHeight = 10.0;

    static float const horizontalSpriteLength = textWidth + textHorizontalPadding * 2;
    static float const verticalSpriteLength = textHeight + textVerticalPadding;

    static float const spriteWidth = 1.0;

    static float const nodeWidth = horizontalSpriteLength + nodePadding * 2;
    static float const nodeHeight = verticalSpriteLength + nodePadding;

    static float const verticalSpriteInset = 0.5;
    static float const verticalSpriteInsetLength = textHeight - verticalSpriteInset * 2;

    static float const textScale = 0.4;
    static float const titleTextScale = 0.5;
    static float const spriteScale = 0.05;

    static cocos2d::CCSize const nodeSize = cocos2d::CCSizeMake(nodeWidth, textHeight);
    static cocos2d::CCSize const nodeBottomSize = cocos2d::CCSizeMake(nodeWidth, nodeHeight);
    static cocos2d::CCSize const textSize = cocos2d::CCSizeMake(nodeWidth / textScale, nodeHeight / textScale);
    static cocos2d::CCSize const titleTextSize = cocos2d::CCSizeMake(nodeWidth / titleTextScale, textHeight / titleTextScale);
    static cocos2d::CCSize const backdropSize = cocos2d::CCSizeMake(nodeWidth, titleTextHeight + 2 * nodePadding);
    static cocos2d::CCSize const horizontalSpriteSize = cocos2d::CCSizeMake(horizontalSpriteLength / spriteScale, 1.0 / spriteScale);
    static cocos2d::CCSize const verticalSpriteSize = cocos2d::CCSizeMake(1.0 / spriteScale, verticalSpriteLength / spriteScale);
    static cocos2d::CCSize const verticalSpriteInsetSize = cocos2d::CCSizeMake(1.0 / spriteScale, verticalSpriteInsetLength / spriteScale);
}
