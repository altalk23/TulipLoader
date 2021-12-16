#pragma once
#include <Cacao>
#include <ModHasher.hpp>
#include <Manager.hpp>
#include <ConfigManager.hpp>
#include <ConfigCategory.hpp>

namespace TLInterface {
    void registerMod(ModContainer* mod) __attribute__((used));

    TLCategoryConfig* registerCategory(std::string name) __attribute__((used));
}
