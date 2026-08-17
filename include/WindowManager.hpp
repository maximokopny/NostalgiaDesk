// include/WindowManager.hpp
#pragma once
#include <vector>
#include "Window.hpp"

class WindowManager {
public:
    void addWindow(Window* w);
    void drawAll();
    void focusNext();
    Window* focused();

private:
    std::vector<Window*> windows_;
    int focusedIndex_ = -1;
};
