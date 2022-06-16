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


void Field::draw_snake_on_field(Snake * snake)
{
    clear_field();

    auto snake_coord = snake->get_snake_coord();
    auto snakes_head_coord = FIELD[snake_coord[0].x][snake_coord[0].y];

    if (FIELD[snake_coord[0].x][snake_coord[0].y] != BORD)
    {
        FIELD[snake_coord[0].x][snake_coord[0].y] = SNAKES_HEAD;
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x >= 1 && snake_coord[0].x <= 13) && (snake_coord[0].y == 0))
    {
        from_left_side_to_right_side(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x >= 1 && snake_coord[0].x <= 13) && (snake_coord[0].y == COLUMNS - 1))
    {
        from_right_side_to_left_side(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x == 0) && (snake_coord[0].y >= 1 && snake_coord[0].y <= COLUMNS - 1))
    {
        from_up_to_down(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x == ROWS - 1) && (snake_coord[0].y >= 1 && snake_coord[0].y <= COLUMNS - 1))
    {
        from_down_to_up(snake);
    }
    
    for (int i = 1; i < snake_coord.size(); i++)
    {
        if (FIELD[snake_coord[i].x][snake_coord[i].y] != BORD)
        {
            FIELD[snake_coord[i].x][snake_coord[i].y] = SNAKES_BODY;
        }
    }
}

void Field::from_left_side_to_right_side(Snake * snake)
{
    auto active_snake_coords = snake->get_snake_coord();
 
    for (int i = 1, j = 0; i < ROWS - 1; i++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = i;
            active_snake_coords[0].y = COLUMNS - 1;
            snake->set_new_coord(active_snake_coords);
            break;
        }
    }

}

void Field::from_right_side_to_left_side(Snake * snake)
{
    auto active_snake_coords = snake->get_snake_coord();

    for (int i = 1, j = COLUMNS - 1; i < ROWS - 1; i++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = i;
            active_snake_coords[0].y = 0;
            snake->set_new_coord(active_snake_coords);
            break;
        }
        
    }
    
}

void Field::from_up_to_down(Snake * snake)
{
    auto active_snake_coords = snake->get_snake_coord();
    for (int i = 0, j = 1; j < COLUMNS - 1; j++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = ROWS - 1;
            active_snake_coords[0].y = j;
            snake->set_new_coord(active_snake_coords);
            break;
        }
    }
}

void Field::from_down_to_up(Snake * snake)
{
    auto active_snake_coords = snake->get_snake_coord();
    for (int i = ROWS - 1, j = 1; j < COLUMNS - 1; j++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = 0;
            active_snake_coords[0].y = j;
            snake->set_new_coord(active_snake_coords);
            break;
        }
    }
}

void Field::clear_field()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (FIELD[i][j] == SNAKES_HEAD || FIELD[i][j] == SNAKES_BODY)
            {
                FIELD[i][j] = EMPTY;
            }
        }
    }
}

bool Field::is_snakes_body(Snake *snake)
{
    auto active_snake_coords = snake->get_snake_coord();
    auto snakes_head_coord = FIELD[active_snake_coords[0].x][active_snake_coords[0].y];
    for (int i = 0; i < active_snake_coords.size(); i++)
    {
        if (snakes_head_coord == SNAKES_BODY)
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    if (FIELD[i][j] == SNAKES_BODY)
                    {
                        FIELD[i][j] = SNAKES_HEAD;
                    }
                }
            }
            return true;
        }
    }
    return false;
}