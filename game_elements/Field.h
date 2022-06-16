#pragma once
#include "Snake.h"
const int ROWS = 15;
const int COLUMNS = 20;

// const int MAX_SIZE_FIELD = 40;
class Field
{
private:
    char FIELD[ROWS][COLUMNS];
public:
    Field();
    void fill_field_by_coord();
    void draw_field();
    void draw_snake_on_field(Snake * snake);
    void from_left_side_to_right_side(Snake * snake);
    void from_right_side_to_left_side(Snake * snake);
    void from_up_to_down(Snake * snake);
    void from_down_to_up(Snake * snake);

    void clear_field();

    bool is_snakes_body(Snake *snake);
};

