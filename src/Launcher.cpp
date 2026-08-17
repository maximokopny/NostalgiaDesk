// src/Launcher.cpp
#include "Launcher.hpp"
#include <ncurses.h>
#include <cstdlib>

void Launcher::run(const std::string& cmd) {
    def_prog_mode();
    endwin();
    system(cmd.c_str());
    reset_prog_mode();
    refresh();
}
