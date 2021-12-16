#define CAC_PROJ_NAME "Megahack uwu"
#include <Cacao>
#include <iostream>

#include <Manager.hpp>
#include <ListLayer.hpp>
#include <ModLayer.hpp>
#include <OverlayLayer.hpp>

class $redirect(CCTextInputNode) {
public:
    void onClickTrackNode(bool state) override {
        auto configTextbox = dynamic_cast<TLOverlayTextbox*>(getUserObject());
        if (configTextbox) {
            if (state) configTextbox->onSelect(this);
            else configTextbox->onDeselect(this);
        }
        return $CCTextInputNode::onClickTrackNode(state);
    }
    bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* p0, char const* p1, int p2) override {
        if ((cocos2d::enumKeyCodes)*p1 == cocos2d::enumKeyCodes::KEY_Escape) {
            onClickTrackNode(false);
            return true;
        }
        else if ((cocos2d::enumKeyCodes)*p1 == cocos2d::enumKeyCodes::KEY_Enter) {
            auto configTextbox = dynamic_cast<TLOverlayTextbox*>(getUserObject());
            if (configTextbox) {
                configTextbox->callback(this);
            }
            onClickTrackNode(false);
            return true;
        }
        return $CCTextInputNode::onTextFieldInsertText(p0, p1, p2);
    }
};

class $redirect(MenuLayer) {
public:
    void onMoreGames(CCObject* sender) {
        auto list = TLModLayer::create();
        addChild(list, 999);
        list->showLayer(false);
    }
};

class $redirect(CCKeyboardDispatcher) {
public:
	static inline TLOverlayLayer* g_overlay;
	bool dispatchKeyboardMSG(cocos2d::enumKeyCodes code, bool press) {
		if (code == cocos2d::enumKeyCodes::KEY_Tab && press) {
		    if (!TLOverlayLayer::isActive() && !cocos2d::CCDirector::sharedDirector()->getIsTransitioning()) {
		        g_overlay = TLOverlayLayer::create();
		        g_overlay->show();
		    }
		    else if (TLOverlayLayer::isActive()) {
		        g_overlay->onClose(nullptr);
		        g_overlay = nullptr;
		    }
		}
		// std::cout << "msg " << code << " " << press << std::endl;
		return $CCKeyboardDispatcher::dispatchKeyboardMSG(code, press);
	}
};

class $redirect(EditorUI) {
public:
	void scrollWheel(float x, float y) {
		std::cout << "scrollWheel " << x << " " << y << std::endl;
		return $EditorUI::scrollWheel(x, y);
	}
};

void inject() {
    std::cout << "Loading mods from the mod folder" << std::endl;
    TLManager::sharedManager();
    std::cout << "Loading Loader" << std::endl;
}
