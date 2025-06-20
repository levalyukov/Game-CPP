cmake_minimum_required(VERSION 3.15)
project(Game-CPP)

set(SFML_ROOT "C:/cpp-libs/SFML")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(Game "src/main.cpp" 
"src/core/game.cpp" 
"src/entities/player.cpp" 
"src/systems/tilemap/tilemap.cpp" 
"src/systems/animations/animations.cpp"
"src/economy/economy.hpp" 
"src/economy/economy.cpp"
"src/entities/entity-manager.hpp" 
"src/entities/entity-manager.cpp" 
"src/entities/entity.hpp" 
"src/entities/entity.cpp" 
"src/systems/collisions/collisions.hpp" 
"src/systems/collisions/collisions.cpp"
"src/systems/audio/audio.cpp" 
"src/systems/audio/audio.hpp" 

"src/ui/gui/gui.cpp"
"src/ui/gui/gui.hpp"
"src/ui/gui/elements/button.cpp"
"src/ui/gui/elements/button.hpp"
"src/ui/gui/elements/text.cpp"
"src/ui/gui/elements/text.hpp"
 "src/ui/ui.cpp")
target_include_directories(Game PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(Game PRIVATE sfml-system sfml-window sfml-audio sfml-graphics)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SFML_DLL_SUFFIX "-d-2.dll")
else()
    set(SFML_DLL_SUFFIX "-2.dll")
endif()

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_ROOT}/bin/sfml-system${SFML_DLL_SUFFIX}"
        "${SFML_ROOT}/bin/sfml-window${SFML_DLL_SUFFIX}"
        "${SFML_ROOT}/bin/sfml-graphics${SFML_DLL_SUFFIX}"
        "${SFML_ROOT}/bin/sfml-audio${SFML_DLL_SUFFIX}"
        "$<TARGET_FILE_DIR:Game>"
)