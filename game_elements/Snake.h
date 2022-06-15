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
    std::deque<coord> get_snake_coord() const;
    coord get_snake_coord_old() const;

    void set_new_direction(Direction new_direction);

    void save_old_cord();

    void move_snake();

    void move_right();
    void move_down();
    void move_left();
    void move_up();
protected:
    std::deque<coord> snake_coord;
    Direction direction = Direction::NO_ACTION;
};
