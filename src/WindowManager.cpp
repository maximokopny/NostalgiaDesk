// src/WindowManager.cpp
#include "WindowManager.hpp"

void WindowManager::addWindow(Window* w) {
    windows_.push_back(w);
    focusedIndex_ = static_cast<int>(windows_.size()) - 1;
}

void WindowManager::drawAll() {
    for (size_t i = 0; i < windows_.size(); ++i) {
        windows_[i]->setFocused(static_cast<int>(i) == focusedIndex_);
        windows_[i]->draw();
    }
}

void WindowManager::focusNext() {
    if (windows_.empty()) return;
    focusedIndex_ = (focusedIndex_ + 1) % static_cast<int>(windows_.size());
}

Window* WindowManager::focused() {
    if (focusedIndex_ < 0 || focusedIndex_ >= static_cast<int>(windows_.size()))
        return nullptr;
    return windows_[focusedIndex_];
}
