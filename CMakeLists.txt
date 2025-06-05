cmake_minimum_required(VERSION 3.15)
project(Game-CPP)

set(SFML_ROOT "H:/cpp-libs/SFML")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(MyApp "src/main.cpp" 
"src/core/game.cpp" 
"src/entities/player.cpp" 
"src/systems/tilemap/tilemap.cpp" 
"src/systems/animations/animations.cpp"
)
target_include_directories(MyApp PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(MyApp PRIVATE sfml-system sfml-window sfml-graphics)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SFML_DLL_SUFFIX "-d-2.dll")
else()
    set(SFML_DLL_SUFFIX "-2.dll")
endif()

add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_ROOT}/bin/sfml-system${SFML_DLL_SUFFIX}"
        "${SFML_ROOT}/bin/sfml-window${SFML_DLL_SUFFIX}"
        "${SFML_ROOT}/bin/sfml-graphics${SFML_DLL_SUFFIX}"
        "$<TARGET_FILE_DIR:MyApp>"
)