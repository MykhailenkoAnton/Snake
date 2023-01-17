#pragma once

#include<deque>
struct coord
{
    int x;
    int y;
};

enum class Direction
{
    DOWN = 0,
    LEFT = 1,
    UP = 2,
    RIGHT = 3,
    NO_ACTION = 4
};
class Snake
{

public:
    Snake();
    std::deque<coord> getSnakeCoord() const;

    void setNewDirection(Direction new_direction);

    void setNewCoord(std::deque<coord>);

    void moveSnake();

    void moveRight();
    void moveDown();
    void moveLeft();
    void moveUp();

    void addNewHead();
protected:
    std::deque<coord> _snakeCoord;
    Direction _direction = Direction::NO_ACTION;
};
