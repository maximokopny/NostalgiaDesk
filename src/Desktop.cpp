// src/Desktop.cpp
#include "Desktop.hpp"
#include "Theme.hpp"

void Desktop::draw() {
    wbkgd(stdscr, COLOR_PAIR(CP_DESKTOP));
    erase();
    // можно добавить логотип/узор
}
