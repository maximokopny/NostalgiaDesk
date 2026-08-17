cmake_minimum_required(VERSION 3.10)
project(NostalgiaDesk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

include_directories(
    ${CURSES_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(nostalgiadesk
    src/main.cpp
    src/Desktop.cpp
    src/LoginScreen.cpp
    src/Localization.cpp
    src/Theme.cpp
    src/Window.cpp
    src/WindowManager.cpp
    src/Taskbar.cpp
    src/Menu.cpp
    src/Launcher.cpp
)

target_link_libraries(nostalgiadesk
    ${CURSES_LIBRARIES}
)
