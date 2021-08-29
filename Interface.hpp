#pragma once
#include <Cacao.hpp>
#include "innerworkings/ModHasher.hpp"
#include "Manager.hpp"
#include "ConfigLayer/ConfigCategory.hpp"
#include "ConfigLayer/ConfigManager.hpp"
#include "ConfigLayer/ExtConfigCategory.hpp"

namespace TLInterface {
    void registerMod(ModContainer* mod) __attribute__((used));

    TLExtConfigCategory* registerCategory(std::string name) __attribute__((used));
}
