// include/Window.hpp
#pragma once
#include <ncurses.h>
#include <string>

class Window {
public:
    Window(int x, int y, int w, int h, const std::string& title);
    ~Window();

    void draw();
    void setFocused(bool f) { focused_ = f; }
    const std::string& title() const { return title_; }

private:
    WINDOW* win_;
    int x_, y_, w_, h_;
    std::string title_;
    bool focused_;
};
