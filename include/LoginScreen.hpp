// include/LoginScreen.hpp
#pragma once
#include <ncurses.h>
#include <string>
#include "Localization.hpp"

class LoginScreen {
public:
    LoginScreen(Localization& loc);
    void draw();
    void handleInput(int ch);
    bool authenticated() const;
private:
    Localization& loc_;
    WINDOW* win_;
    int w_, h_, x_, y_;
    std::string username_;
    std::string password_;
    bool enteringPassword_;
    bool authOk_;
};
