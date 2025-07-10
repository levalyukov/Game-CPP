cmake_minimum_required(VERSION 3.15)
project(Game-CPP)

set(SFML_ROOT "C:/cpp-libs/SFML")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(Game 
"src/main.cpp" 
"src/core/game.cpp" 

"src/economy/economy.hpp" 
"src/economy/economy.cpp"

"src/entities/entity-manager.hpp" 
"src/entities/entity.hpp"
"src/entities/entities/player.cpp" 
"src/entities/entities/player.hpp" 

"src/core/tilemap/tilemap.cpp" 
"src/core/tilemap/tilemap.hpp" 
"src/core/animations/animations.cpp"
"src/core/animations/animations.hpp"
"src/core/collisions/collisions.hpp" 
"src/core/collisions/collisions.cpp"
"src/core/audio/audio.cpp" 
"src/core/audio/audio.hpp" 

"src/ui/core/ui.hpp"
"src/ui/core/gui.hpp"

"src/ui/core/elements/ui-element.hpp"
"src/ui/core/elements/label.hpp"
"src/ui/core/elements/button.cpp" 
"src/ui/core/elements/button.hpp" 

"src/ui/screens/hud.cpp"
"src/ui/screens/hud.hpp"

"src/core/debug/debug.cpp"
"src/core/debug/debug.hpp"

"src/core/resources/resources.hpp"
"src/core/resources/resources.cpp")
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