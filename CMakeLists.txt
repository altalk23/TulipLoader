cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(TulipLoader VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES
    Main.cpp 
    Manager.cpp 
    Interface.cpp 
    ModLayer.cpp 
    ModCell.cpp 
    ListLayer.cpp 
    Inner/FileTraversal.m
    Overlay/OverlayLayer.cpp 
    Config/ConfigManager.cpp 
    Config/ConfigCategory.cpp 
    Overlay/Item/Category.cpp 
    Overlay/Item/Backdrop.cpp 
    Overlay/Item/Toggle.cpp 
    Overlay/Item/Button.cpp 
    Overlay/Item/Textbox.cpp 
    Overlay/Item/Radio.cpp 
)

set(LINK_LIBRARIES 
	toml
    "-framework Foundation"
)

set(LINK_DIRECTORIES 
	PUBLIC toml/lib
)

set(INCLUDE_DIRECTORIES
	toml/include
	.
	Overlay
	Config
	Inner
)

include(Cacao/cmake/CacaoRoot.cmake)


# cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# # Available platforms:
# # MacOS
# # Win32
# if (APPLE)
#     set(CACAO_TARGET_PLATFORM "MacOS")
# elseif (WIN32)
#     set(CACAO_TARGET_PLATFORM "Win32")
# endif ()

# project(TulipLoader VERSION 0.1.0 LANGUAGES C CXX)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions -Xlinker --no-demangle")
# set(CMAKE_BUILD_TYPE RelWithDebugInfo)
# set(CMAKE_CXX_STANDARD 17)


# include_directories(
#     Cacao/
#     Cacao/base
#     Cacao/compat
#     Cacao/core
#     Cacao/include/cocos-headers
#     Cacao/include/cocos-headers/cocos2dx
#     Cacao/include/cocos-headers/cocos2dx/include
#     Cacao/include/cocos-headers/cocos2dx/kazmath/include
#     Cacao/include/cocos-headers/extensions
#     Cacao/include/cocos-headers/cocos2dx/custom/Sprites/CCMenuItemSpriteExtra
#     toml
#     toml/include
# )

# if("${CACAO_TARGET_PLATFORM}" STREQUAL "MacOS")
#     include_directories(
#         Cacao/api 
#         Cacao/include/cocos-headers/cocos2dx/platform/mac
#         Cacao/include/cocos-headers/cocos2dx/platform/third_party/mac
#         Cacao/include/cocos-headers/cocos2dx/platform/third_party/mac/OGLES
#     )
    
#     add_definitions(-DCC_TARGET_OS_MAC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated ")

#     add_custom_command(
#         COMMAND sudo osxinj \"Geometry Dash\" *.dylib || true
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Inject target ${PROJECT_NAME}"
#         OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/run0
#     )

#     add_custom_target(
#         Inject ALL
#         DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/run0
#     )

#     add_dependencies(Inject ${PROJECT_NAME})

# elseif("${CACAO_TARGET_PLATFORM}" STREQUAL "Win32")
#     include_directories(
#         Cacao/include/cocos-headers/cocos2dx/platform/win32
#         Cacao/include/cocos-headers/cocos2dx/platform/third_party/win32
#         Cacao/include/cocos-headers/cocos2dx/platform/third_party/win32/OGLES
#     )
#     target_link_libraries(${PROJECT_NAME} 
#         Cacao/include/cocos-headers/cocos2dx/libcocos2d.lib
#         Cacao/include/cocos-headers/extensions/libExtensions.lib
#     )
#     set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
#     set(CMAKE_SIZEOF_VOID_P 4)
#     set(CMAKE_SYSTEM_PROCESSOR "i686")
#     set(CMAKE_GENERATOR_PLATFORM x86)
#     install(
#         TARGETS ${PROJECT_NAME} 
#         DESTINATION ${CMAKE_BINARY_DIR}/out/
#     )
# else()
# endif()

# add_subdirectory(Cacao)

# add_library(${PROJECT_NAME} SHARED 
#     Main.cpp 
#     Manager.cpp 
#     Interface.cpp 
#     ModLayer.cpp 
#     ModCell.cpp 
#     ListLayer.cpp 
#     innerworkings/FileTraversal.m
#     ConfigLayer/ConfigOverlay.cpp 
#     ConfigLayer/ConfigManager.cpp 
#     ConfigLayer/ConfigCategory.cpp 
#     ConfigLayer/ExtConfigCategory.cpp 
#     ConfigLayer/Item/ConfigBackdrop.cpp 
#     ConfigLayer/Item/ConfigToggle.cpp 
#     ConfigLayer/Item/ConfigButton.cpp 
#     ConfigLayer/Item/ConfigTextbox.cpp 
#     ConfigLayer/Item/ConfigRadio.cpp 
# )
# target_link_directories(${PROJECT_NAME} 
#     PRIVATE Cacao
#     PUBLIC toml/lib
# )
# target_link_libraries(${PROJECT_NAME} 
#     Cacao
#     toml
#     "-framework Foundation"
# )

# target_include_directories(${PROJECT_NAME} 
#     PUBLIC . toml/include
# )

