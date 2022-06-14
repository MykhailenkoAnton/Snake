#include "Gamesnake.h"
#include "Field.h"
#include <time.h>
const int DELAY = 100000;
GameSnake::GameSnake()
{
}
void GameSnake::run()
{
    while (true)
    {
        field_.fill_field_by_coord();
        field_.draw_field();
        reading_user_input();
    }
}

void GameSnake::sleep_and_user_choice()
{
    clock_t end_time = clock() + DELAY;
    const auto user_input = reading_user_input();
    while (clock() < end_time);
    {
        
    }
    
}

eActoins GameSnake::reading_user_input()
{

}