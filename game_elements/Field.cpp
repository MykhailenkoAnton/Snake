#include <iostream>
#include "Field.h"
const char BORD = 'X';
const char EMPTY = ' ';

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