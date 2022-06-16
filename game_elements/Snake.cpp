#include <cstdlib>
#include "Snake.h"
extern const int ROWS;
extern const int COLUMNS;
Snake::Snake()
{
    coord head = {7, 10};
    snake_coord.push_front(head);
    coord body = {8, 10};
    snake_coord.push_back(body);
    coord body1 = {9, 10};
    snake_coord.push_back(body1);
    coord body2 = {10, 10};
    snake_coord.push_back(body2);

}

std::deque<coord> Snake::get_snake_coord() const
{
    return snake_coord;
}


void Snake::move_snake()
{
    switch (direction)
    {
    case Direction::DOWN:
        move_down();
        break;
    case Direction::UP:
        move_up();
        break;
    case Direction::RIGHT:
        move_right();
        break;
    case Direction::LEFT:
        move_left();
        break;
    default:
        break;
    }
}

void Snake::set_new_direction(Direction new_direction)
{
    direction = new_direction;
}

void Snake::move_right()
{
    if (snake_coord.size() == 1)
    {
        snake_coord[0].y++;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = snake_coord[0].x;
        snake_new_head.y = snake_coord[0].y + 1;
        snake_coord.push_front(snake_new_head);
        snake_coord.pop_back();
    }
}

void Snake::move_left()
{
    if (snake_coord.size() == 1)
    {
        snake_coord[0].y--;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = snake_coord[0].x;
        snake_new_head.y = snake_coord[0].y - 1;
        snake_coord.push_front(snake_new_head);
        snake_coord.pop_back();
    }
}

void Snake::move_down()
{
    if (snake_coord.size() == 1)
    {
        snake_coord[0].x++;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = snake_coord[0].x + 1;
        snake_new_head.y = snake_coord[0].y;
        snake_coord.push_front(snake_new_head);
        snake_coord.pop_back();
    }
}

void Snake::move_up()
{
    if (snake_coord.size() == 1)
    {
        snake_coord[0].x--;
    }
    else
    {
        coord snake_new_head;
        snake_new_head.x = snake_coord[0].x - 1;
        snake_new_head.y = snake_coord[0].y;
        snake_coord.push_front(snake_new_head);
        snake_coord.pop_back();
    }
}


void Snake::set_new_coord(std::deque<coord> new_snake_coord )
{
    snake_coord[0].x = new_snake_coord[0].x;
    snake_coord[0].y = new_snake_coord[0].y;
}