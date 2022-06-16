#include <conio.h>
#include <time.h>
#include "Gamesnake.h"
#include "Field.h"
#include "Snake.h"
#include "Fruits.h"
const int DELAY = 600000;
GameSnake::GameSnake()
{
}
void GameSnake::run()
{
    Fruits fruit;
    Snake snake1;
    field_.draw_fruit(&fruit);
    while (!game_status)
    {
        if (field_.is_snakes_body(&snake1))
        {
            game_status = true;
        }
        else
        {
            if (field_.is_eating_for_snake(&snake1, &fruit))
            {
                fruit.set_new_coord_for_fruit();
                field_.draw_fruit(&fruit);
            }
            snake1.move_snake();
            field_.draw_snake_on_field(&snake1);
            field_.draw_field();
            sleep_and_user_choice(&snake1);
        }
    }
}

void GameSnake::sleep_and_user_choice(Snake *snake)
{
    clock_t end_time = clock() + DELAY;
    while (clock() < end_time);
    {
        const auto user_input = reading_user_input();
        switch (user_input)
        {
        case eActoins::LEFT:
            snake->set_new_direction(Direction::LEFT);
            break;
        case eActoins::RIGHT:
            snake->set_new_direction(Direction::RIGHT);
            break;
        case eActoins::DOWN:
            snake->set_new_direction(Direction::DOWN);
            break;
        case eActoins::UP:
            snake->set_new_direction(Direction::UP);
            break;
        default:
            break;
        }
    }
    
}


eActoins GameSnake::reading_user_input()
{
    if (kbhit())
    {
        const auto ch = getch();
        switch (ch)
        {
        case 'a':
            return eActoins::LEFT;
            break;
        case 's':
            return eActoins::DOWN;
            break;
        case 'd':
            return eActoins::RIGHT;
            break;
        case 'w':
            return eActoins::UP;
            break;
        case '0':
            // Use '0' for exit from thegame.
            exit(0);
        default:
            break;
        }
    }

    return eActoins::NO_ACTIONS;
}