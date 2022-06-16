#include <iostream>
#include "Field.h"
const char BORD = 'X';
const char EMPTY = ' ';
const char SNAKES_HEAD = '0';
const char SNAKES_BODY = 'o';
Field::Field()
{
    fill_field_by_coord();
}
void Field::fill_field_by_coord()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            if (row == 0 || row == ROWS - 1)
            {
                FIELD[row][column] = BORD;
            }
            else if (column == 0 || column == COLUMNS - 1)
            {
                FIELD[row][column] = BORD;
            }
            else
            {
                FIELD[row][column] = EMPTY;
            }
        }
    }
}
void Field::draw_field()
{
    system("clear");
    
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            std::cout << FIELD[row][column];
        }
        std::cout << std::endl;
    }
}


void Field::draw_snake_on_field(const Snake * snake)
{
    clear_field();
    const auto snake_coord = snake->get_snake_coord();
    FIELD[snake_coord[0].x][snake_coord[0].y] = SNAKES_HEAD;
    for (int i = 1; i < snake_coord.size(); i++)
    {
        FIELD[snake_coord[i].x][snake_coord[i].y] = SNAKES_BODY;
    }
    
}

void Field::from_left_side_to_right_side(Snake * snake)
{
    auto snake_coord = snake->get_snake_coord();
    for (int i = 1, j = 0; i < ROWS - 1; i++)
    {
        if (FIELD[snake_coord[0].x][snake_coord[0].y] == FIELD[i][j])
        {
            snake_coord[0].x = i;
            snake_coord[0].y = COLUMNS - 1;
            snake->set_new_coord(snake_coord);
            break;
        }
        
    }
    
    
}

void Field::clear_field()
{
    for (int i = 0; i < ROWS - 1; i++)
    {
        for (int j = 0; j < COLUMNS - 1; j++)
        {
            if (FIELD[i][j] == SNAKES_HEAD || FIELD[i][j] == SNAKES_BODY)
            {
                FIELD[i][j] = EMPTY;
            }
            
        }
    }
}

// bool Field::is_snakes_body_on_right_side(Snake *snake)
// {

//     return false;
// }

// bool Field::is_snakes_body_on_left_side(Snake *snake)
// {

//     return false;
// }

// bool Field::is_snakes_body_on_down(Snake *snake)
// {

//     return false;
// }

// bool Field::is_snakes_body_on_up(Snake *snake)
// {

//     return false;
// }