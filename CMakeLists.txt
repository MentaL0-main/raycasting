cmake_minimum_required(VERSION 3.16)
project(RaycasterSDL3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp
                               src/window.cpp
                               src/renderer.cpp
                               src/raycast.cpp
                               src/player.cpp
                               src/world.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

