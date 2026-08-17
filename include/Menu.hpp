// include/Menu.hpp
#pragma once
#include <ncurses.h>
#include "Localization.hpp"

class Menu {
public:
    Menu(Localization& loc);
    void draw();
    void toggle();
    bool visible() const { return visible_; }
private:
    Localization& loc_;
    WINDOW* win_;
    bool visible_;
};
