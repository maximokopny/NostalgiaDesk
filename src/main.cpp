// src/main.cpp
#include <ncurses.h>
#include "Theme.hpp"
#include "Localization.hpp"
#include "LoginScreen.hpp"
#include "Desktop.hpp"
#include "Window.hpp"
#include "WindowManager.hpp"
#include "Taskbar.hpp"
#include "Menu.hpp"
#include "Launcher.hpp"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    Theme::init();

    Localization loc;
    loc.load("ru"); // потом можно сделать выбор языка

    // 1. Экран логина
    LoginScreen login(loc);
    while (!login.authenticated()) {
        login.draw();
        int ch = getch();
        login.handleInput(ch);
    }

    // 2. Рабочий стол
    Desktop desktop;
    WindowManager wm;
    Taskbar taskbar(loc);
    Menu menu(loc);

    // тестовое окно
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    auto* win = new Window(2, 2, cols - 4, rows - 4 - 1, loc.t("window.explorer"));
    wm.addWindow(win);

    while (true) {
        desktop.draw();
        wm.drawAll();
        // собрать заголовки окон
        std::vector<std::string> titles;
        // (упрощённо: один)
        titles.push_back(win->title());
        taskbar.draw(titles);
        menu.draw();

        refresh();

        int ch = getch();
        if (ch == 'q') break;
        if (ch == '\t') wm.focusNext();
        if (ch == KEY_F(1)) menu.toggle();
        if (ch == KEY_F(2)) Launcher::run("tilde");
    }

    endwin();
    return 0;
}
