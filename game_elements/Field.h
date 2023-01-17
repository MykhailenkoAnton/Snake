#pragma once

#include "Snake.h"
#include "Fruits.h"

const int ROWS = 15;
const int COLUMNS = 20;

class Field
{
private:
    char _Field[ROWS][COLUMNS];
public:
    Field();
    void fillFieldByCoord();
    void drawField(int game_point);
    void drawSnakeOnField(Snake * snake);
    void fromLeftSideToRightSide(Snake * snake);
    void fromRightSideToLeftSide(Snake * snake);
    void fromUpToDown(Snake * snake);
    void fromDownToUp(Snake * snake);
    void clearField();
    bool isSnakesBody(Snake *snake);
    void drawFruit(Fruits * fruits);
    bool isEatingForSnake(Snake * snake, Fruits * fruits);
};

