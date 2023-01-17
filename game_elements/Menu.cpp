#include <iostream>

#include "Menu.h"

Menu::Menu()
{
    menu.push_back({" START GAME ", 7, true});
    menu.push_back({" EXIT ", 7, false});
}

void Menu::color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Menu::gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Menu::showMenu()
{
    while (true)
    {
        gotoxy(8, 5);
        color(menu[0].color);
        std::cout << " START GAME ";

        gotoxy(8, 6);
        color(menu[1].color);
        std::cout << " EXIT ";

        key = _getch();

        // arrow control
        if (key == 80 && (counter >=0 && counter < 1)) 
        {
            counter ++;
            menu[0].active = false;
            menu[1].active = true;
        }
        if (key == 72 && (counter >= 1 && counter < 2))
        {
            counter --;
            menu[0].active = true;
            menu[1].active = false;
        }
        if(key == 13) // enter press
        {
            if (menu[0].active == true)
            {
                break;
            }
            else{
                exit(0);
            }
        }

        menu[0].color = 7;
        menu[1].color = 7;
        if (counter == 0)
        {            
            menu[0].color = 12;
        }
        if (counter == 1)
        {
            menu[1].color = 12;
        }
    }
}