// src/Taskbar.cpp
#include "Taskbar.hpp"
#include "Theme.hpp"

Taskbar::Taskbar(Localization& loc)
    : loc_(loc)
{
    getmaxyx(stdscr, h_, w_);
    bar_ = newwin(1, w_, h_ - 1, 0);
}

void Taskbar::draw(const std::vector<std::string>& titles) {
    wbkgd(bar_, COLOR_PAIR(CP_TASKBAR));
    werase(bar_);
    mvwprintw(bar_, 0, 1, "[ %s ]", loc_.t("menu.start").c_str());

    int x = 15;
    for (auto& t : titles) {
        mvwprintw(bar_, 0, x, "[%s]", t.c_str());
        x += static_cast<int>(t.size()) + 4;
    }

    wrefresh(bar_);
}
