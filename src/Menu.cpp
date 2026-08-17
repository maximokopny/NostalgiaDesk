// src/Menu.cpp
#include "Menu.hpp"
#include "Theme.hpp"

Menu::Menu(Localization& loc)
    : loc_(loc), visible_(false)
{
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    win_ = newwin(10, 20, rows - 11, 0);
}

void Menu::toggle() {
    visible_ = !visible_;
}

void Menu::draw() {
    if (!visible_) return;
    wbkgd(win_, COLOR_PAIR(CP_MENU));
    werase(win_);
    box(win_, 0, 0);
    mvwprintw(win_, 1, 2, "%s", loc_.t("window.explorer").c_str());
    mvwprintw(win_, 2, 2, "tilde");
    mvwprintw(win_, 3, 2, "mc");
    wrefresh(win_);
}
