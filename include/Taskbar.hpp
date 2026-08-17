// include/Taskbar.hpp
#pragma once
#include <ncurses.h>
#include <vector>
#include <string>
#include "Localization.hpp"

class Taskbar {
public:
    Taskbar(Localization& loc);
    void draw(const std::vector<std::string>& titles);

private:
    Localization& loc_;
    WINDOW* bar_;
    int w_, h_;
};
