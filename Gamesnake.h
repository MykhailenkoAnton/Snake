#pragma once

#include "Field.h"

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

public:
    GameSnake();
    void run();
    
private:
    void userChoice(Snake  *snake);
    eActoins readingUserInput();

private:
    bool _gameStatus = false;
    int _gamePoint = 0;

    Field field_;
};
