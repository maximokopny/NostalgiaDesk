// include/Theme.hpp
#pragma once
#include <ncurses.h>

enum ColorPair {
    CP_DESKTOP = 1,
    CP_WINDOW_NORMAL,
    CP_WINDOW_FOCUS,
    CP_TASKBAR,
    CP_SHADOW,
    CP_MENU
};

struct Theme {
    static void init();
};
