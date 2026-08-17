cmake_minimum_required(VERSION 3.10)
project(NostaDE_ncurses CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(include)

add_executable(NostaDE-ncurses
    src/main.cpp
    src/Theme.cpp
    src/Localization.cpp
    src/LoginScreen.cpp
    src/Desktop.cpp
    src/Window.cpp
    src/WindowManager.cpp
    src/Taskbar.cpp
    src/Menu.cpp
    src/Launcher.cpp
)

target_link_libraries(NostaDE-ncurses ${CURSES_LIBRARIES})
