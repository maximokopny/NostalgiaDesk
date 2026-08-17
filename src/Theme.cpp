// src/Theme.cpp
#include "Theme.hpp"

void Theme::init() {
    start_color();
    use_default_colors();

    init_pair(CP_DESKTOP, COLOR_BLUE,   -1);
    init_pair(CP_WINDOW_NORMAL, COLOR_WHITE, COLOR_BLUE);
    init_pair(CP_WINDOW_FOCUS,  COLOR_YELLOW, COLOR_BLUE);
    init_pair(CP_TASKBAR,       COLOR_BLACK, COLOR_CYAN);
    init_pair(CP_SHADOW,        COLOR_BLACK, -1);
    init_pair(CP_MENU,          COLOR_WHITE, COLOR_BLACK);
}
