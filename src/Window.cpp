// src/Window.cpp
#include "Window.hpp"
#include "Theme.hpp"

Window::Window(int x, int y, int w, int h, const std::string& title)
    : x_(x), y_(y), w_(w), h_(h), title_(title), focused_(false)
{
    win_ = newwin(h_, w_, y_, x_);
}

Window::~Window() {
    delwin(win_);
}

void Window::draw() {
    wbkgd(win_, COLOR_PAIR(focused_ ? CP_WINDOW_FOCUS : CP_WINDOW_NORMAL));
    werase(win_);
    box(win_, 0, 0);
    mvwprintw(win_, 0, 2, "[ %s ]", title_.c_str());
    // здесь позже будет содержимое окна
    wrefresh(win_);
}
