#pragma once

#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>

class Menu
{

public:

    Menu();

    void color(int color);
    void gotoxy(int x, int y);

    void showMenu();

private:
    struct menuItem
    {
        std::string name;
        int color = 7;
        bool active = false;
    };

    char counter = 1;
    char key;
    std::vector<menuItem> menu;
};
