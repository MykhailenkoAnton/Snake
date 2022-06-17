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
    bool game_status = false;
    int game_point = 0;
public:
    GameSnake();
    void run();
    void sleep_and_user_choice(Snake  *snake);
    eActoins reading_user_input();
    void update_snake_on_field_and_sleep(Snake  *snake);
private:
    Field field_;
};
