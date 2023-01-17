#include <cstdlib>

#include "Snake.h"

extern const int ROWS;
extern const int COLUMNS;
Snake::Snake()
{
    coord head = {7, 10};
    _snakeCoord.push_front(head);
}

std::deque<coord> Snake::getSnakeCoord() const
{
    return _snakeCoord;
}

// move snake after change direction
void Snake::moveSnake()
{
    switch (_direction)
    {
    case Direction::DOWN:
        moveDown();
        break;
    case Direction::UP:
        moveUp();
        break;
    case Direction::RIGHT:
        moveRight();
        break;
    case Direction::LEFT:
        moveLeft();
        break;
    default:
        break;
    }
}

void Snake::setNewDirection(Direction new_direction)
{
    _direction = new_direction;
}

void Snake::moveRight()
{
    if (_snakeCoord.size() == 1)
    {
        _snakeCoord[0].y++;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = _snakeCoord[0].x;
        snake_new_head.y = _snakeCoord[0].y + 1;
        _snakeCoord.push_front(snake_new_head);
        _snakeCoord.pop_back();
    }
}

void Snake::moveLeft()
{
    if (_snakeCoord.size() == 1)
    {
        _snakeCoord[0].y--;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = _snakeCoord[0].x;
        snake_new_head.y = _snakeCoord[0].y - 1;
        _snakeCoord.push_front(snake_new_head);
        _snakeCoord.pop_back();
    }
}

void Snake::moveDown()
{
    if (_snakeCoord.size() == 1)
    {
        _snakeCoord[0].x++;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = _snakeCoord[0].x + 1;
        snake_new_head.y = _snakeCoord[0].y;
        _snakeCoord.push_front(snake_new_head);
        _snakeCoord.pop_back();
    }
}

void Snake::moveUp()
{
    if (_snakeCoord.size() == 1)
    {
        _snakeCoord[0].x--;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = _snakeCoord[0].x - 1;
        snake_new_head.y = _snakeCoord[0].y;
        _snakeCoord.push_front(snake_new_head);
        _snakeCoord.pop_back();
    }
}


void Snake::setNewCoord(std::deque<coord> new_snake_coord )
{
    _snakeCoord[0].x = new_snake_coord[0].x;
    _snakeCoord[0].y = new_snake_coord[0].y;
}

// if snake find and eat fruit
void Snake::addNewHead()
{
    coord snake_new_head;
    snake_new_head.x = _snakeCoord[0].x;
    snake_new_head.y = _snakeCoord[0].y;
    _snakeCoord.push_back(snake_new_head);
}