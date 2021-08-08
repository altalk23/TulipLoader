#pragma once
#include <Cacao.hpp>
#include <dlfcn.h>
#include <mach-o/dyld.h>

namespace MHExt {
	typedef void(*registerModType)(ModContainer*);

	registerModType registerMod;

	bool g_initialized = false;

	bool init() {
		int imageCount = _dyld_image_count();
		void* dylib = nullptr;

		for (int i = 0; i < imageCount; ++i) {
			std::string imageName = _dyld_get_image_name(i);
			if (imageName.find("libMegaHack.dylib") != std::string::npos) {
				dylib = dlopen(_dyld_get_image_name(i), RTLD_LAZY | RTLD_NOLOAD);
				break;
			}
		}
		if (dylib == nullptr) return false;

		registerMod = reinterpret_cast<registerModType>(dlsym(dylib, "_ZN11MHInterface11registerModEP12ModContainer"));
		if (registerMod == nullptr) return false;
		
		return g_initialized = true;
	}
}

#define $MHapply() void __mh_apply() {									\
    __if_exists(inject) {												\
    	inject();														\
    }																	\
    for (auto& i : __cackit::glob) i->apply_hooks();					\
    if (MHExt::g_initialized) {											\
    	MHExt::registerMod(m);											\
    }																	\
    else if (__cackit::glob.size() > 0) m->enable();					\
}																		\
static int const __mh_register = (__mh_apply(), 0)
