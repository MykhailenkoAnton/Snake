#pragma once
#include "Field.h"
#include <iostream>

enum class eActoins
{
    NO_ACTIONS = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
    RIGHT = 4
};
class GameSnake
{
private:
public:
    GameSnake();
    void run();
    void sleep_and_user_choice();
    eActoins reading_user_input();
private:
    Field field_;
};