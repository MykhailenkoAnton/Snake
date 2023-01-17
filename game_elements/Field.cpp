#include <iostream>

#include "Field.h"

const char BORD = 'X';
const char EMPTY = ' ';
const char SNAKES_HEAD = '0';
const char SNAKES_BODY = 'o';
const char FRUIT = 'F';

Field::Field()
{
    fillFieldByCoord();
}

void Field::fillFieldByCoord()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            if (row == 0 || row == ROWS - 1)
            {
                _Field[row][column] = BORD;
            }
            else if (column == 0 || column == COLUMNS - 1)
            {
                _Field[row][column] = BORD;
            }
            else
            {
                _Field[row][column] = EMPTY;
            }
        }
    }
}

void Field::drawField(int game_point)
{
    system("clear");
    std::cout << "Game point: " << game_point <<"\nSnake contol with \'w\' \'a\' \'s\' \'d\' \nP.S. (press \'q\' to quit from game)" << std::endl;
    
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            std::cout << _Field[row][column];
        }
        std::cout << std::endl;
    }
}

void Field::drawSnakeOnField(Snake * snake)
{
    clearField();
    auto snake_coord = snake->getSnakeCoord();
    auto snakes_head_coord = _Field[snake_coord[0].x][snake_coord[0].y];

    if (_Field[snake_coord[0].x][snake_coord[0].y] != BORD)
    {
        _Field[snake_coord[0].x][snake_coord[0].y] = SNAKES_HEAD;
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x >= 1 && snake_coord[0].x <= 13) && (snake_coord[0].y == 0)) // if snake touch left board
    {
        fromLeftSideToRightSide(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x >= 1 && snake_coord[0].x <= 13) && (snake_coord[0].y == COLUMNS - 1)) // if snake touch right board
    {
        fromRightSideToLeftSide(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x == 0) && (snake_coord[0].y >= 1 && snake_coord[0].y <= COLUMNS - 1)) // if snake touch up board
    {
        fromUpToDown(snake);
    }
    else if (snakes_head_coord == BORD && (snake_coord[0].x == ROWS - 1) && (snake_coord[0].y >= 1 && snake_coord[0].y <= COLUMNS - 1)) // if snake touch down board
    {
        fromDownToUp(snake);
    }
    
    for (int i = 1; i < snake_coord.size(); i++)
    {
        if (_Field[snake_coord[i].x][snake_coord[i].y] != BORD)
        {
            _Field[snake_coord[i].x][snake_coord[i].y] = SNAKES_BODY;
        }
    }
}

// new snake coord after touching
void Field::fromLeftSideToRightSide(Snake * snake)
{
    auto active_snake_coords = snake->getSnakeCoord();
 
    for (int i = 1, j = 0; i < ROWS - 1; i++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = i;
            active_snake_coords[0].y = COLUMNS - 1;
            snake->setNewCoord(active_snake_coords);
            break;
        }
    }

}

// new snake coord after touching
void Field::fromRightSideToLeftSide(Snake * snake)
{
    auto active_snake_coords = snake->getSnakeCoord();

    for (int i = 1, j = COLUMNS - 1; i < ROWS - 1; i++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = i;
            active_snake_coords[0].y = 0;
            snake->setNewCoord(active_snake_coords);
            break;
        }
        
    }
    
}

// new snake coord after touching
void Field::fromUpToDown(Snake * snake)
{
    auto active_snake_coords = snake->getSnakeCoord();
    for (int i = 0, j = 1; j < COLUMNS - 1; j++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = ROWS - 1;
            active_snake_coords[0].y = j;
            snake->setNewCoord(active_snake_coords);
            break;
        }
    }
}

// new snake coord after touching
void Field::fromDownToUp(Snake * snake)
{
    auto active_snake_coords = snake->getSnakeCoord();
    for (int i = ROWS - 1, j = 1; j < COLUMNS - 1; j++)
    {
        if (active_snake_coords[0].x == i && active_snake_coords[0].y == j)
        {
            active_snake_coords[0].x = 0;
            active_snake_coords[0].y = j;
            snake->setNewCoord(active_snake_coords);
            break;
        }
    }
}

void Field::clearField()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (_Field[i][j] == SNAKES_HEAD || _Field[i][j] == SNAKES_BODY)
            {
                _Field[i][j] = EMPTY;
            }
        }
    }
}

// if snake body, snake is die.
bool Field::isSnakesBody(Snake *snake)
{
    auto active_snake_coords = snake->getSnakeCoord();
    auto snakes_head_coord = _Field[active_snake_coords[0].x][active_snake_coords[0].y];
    for (int i = 0; i < active_snake_coords.size(); i++)
    {
        if (snakes_head_coord == SNAKES_BODY)
        {
            for (int j = 0; j < active_snake_coords.size(); j++)
            {
                _Field[active_snake_coords[j].x][active_snake_coords[j].y] = SNAKES_HEAD;
            }
            
            return true;
        }
    }
    return false;
}

void Field::drawFruit(Fruits * fruits)
{
    auto frut_coord = fruits->getCoordFruit();
    _Field[frut_coord.x][frut_coord.y] = FRUIT;
}

bool Field::isEatingForSnake(Snake * snake, Fruits * fruits)
{
    auto frut_coord = fruits->getCoordFruit();

    auto active_snake_coords = snake->getSnakeCoord();
    auto snakes_head_coord = _Field[active_snake_coords[0].x][active_snake_coords[0].y];

    if (active_snake_coords[0].x == frut_coord.x && active_snake_coords[0].y == frut_coord.y)
    {
        return true;
    }
    
    return false;
}

