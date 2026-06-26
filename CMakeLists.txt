cmake_minimum_required(VERSION 4.1)
project(Life_Simulation)

set(CMAKE_CXX_STANDARD 23)

add_executable(Life_Simulation main.cpp)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
        raygui
        URL https://github.com/raysan5/raygui/archive/master.tar.gz
)
FetchContent_MakeAvailable(raygui)

# On lie (link) Raylib à ton exécutable
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raygui_SOURCE_DIR}/src)
