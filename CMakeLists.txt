cmake_minimum_required(VERSION 4.0)

project(wm)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    GL
    X11
    X11-xcb
    xcb
    xcb-errors
    xcb-keysyms
    xcb-ewmh
    xcb-composite
    xcb-util
    xcb-randr
    xcb-damage
)

add_subdirectory(src)

