#pragma once 

#include <Cacao.hpp>
#include <vector>
#include <dlfcn.h>

inline std::vector<ModContainer*> loadDylib(char const* path) {
	void *dylib = dlopen(path, RTLD_NOW);
	std::vector<ModContainer*>* localContainers = nullptr;

	if (dylib) {
		void* containerPointer = dlsym(dylib, "_ZN12ModContainer10containersE");
		localContainers = reinterpret_cast<std::vector<ModContainer*>*>(containerPointer);
	}

	if (localContainers == nullptr) return std::vector<ModContainer*>{};
	else return *localContainers;
}
