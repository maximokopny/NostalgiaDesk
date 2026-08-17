// src/LoginScreen.cpp
#include "LoginScreen.hpp"

LoginScreen::LoginScreen(Localization& loc)
    : loc_(loc), enteringPassword_(false), authOk_(false)
{
    getmaxyx(stdscr, h_, w_);
    int winw = 40, winh = 10;
    x_ = (w_ - winw) / 2;
    y_ = (h_ - winh) / 2;
    win_ = newwin(winh, winw, y_, x_);
}

void LoginScreen::draw() {
    wbkgd(stdscr, COLOR_PAIR(CP_DESKTOP));
    erase();

    wbkgd(win_, COLOR_PAIR(CP_WINDOW_NORMAL));
    werase(win_);
    box(win_, 0, 0);

    mvwprintw(win_, 1, 2, "%s:", loc_.t("login.username").c_str());
    mvwprintw(win_, 2, 2, "%s:", loc_.t("login.password").c_str());

    mvwprintw(win_, 1, 12, "%s", username_.c_str());
    std::string masked(password_.size(), '*');
    mvwprintw(win_, 2, 12, "%s", masked.c_str());

    mvwprintw(win_, 4, 2, "[ %s ]", loc_.t("login.enter").c_str());
    mvwprintw(win_, 4, 20, "[ %s ]", loc_.t("menu.shutdown").c_str());

    if (!authOk_ && (!username_.empty() || !password_.empty())) {
        mvwprintw(win_, 6, 2, "%s", loc_.t("login.error").c_str());
    }

    wrefresh(win_);
    refresh();
}

void LoginScreen::handleInput(int ch) {
    if (ch == '\t') {
        enteringPassword_ = !enteringPassword_;
        return;
    }
    if (ch == KEY_BACKSPACE || ch == 127) {
        auto& s = enteringPassword_ ? password_ : username_;
        if (!s.empty()) s.pop_back();
        return;
    }
    if (ch == '\n') {
        // временно: любой логин/пароль принимаем
        if (!username_.empty() && !password_.empty()) {
            authOk_ = true;
        }
        return;
    }
    if (ch == 'q') {
        // выключение
        endwin();
        system("shutdown -h now");
    }
    if (ch >= 32 && ch <= 126) {
        auto& s = enteringPassword_ ? password_ : username_;
        s.push_back(static_cast<char>(ch));
    }
}

bool LoginScreen::authenticated() const {
    return authOk_;
}
