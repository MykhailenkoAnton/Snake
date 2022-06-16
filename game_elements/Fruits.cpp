#include "Fruits.h"
#include <cstdlib>
#include <ctime>
const int MAX_ROW = 13;
const int MAX_COL = 18;
Fruits::Fruits()
{
    srand(time(0));
    frui.x = rand() % MAX_ROW;
    frui.y = rand() % MAX_COL;
}

fruit_coord Fruits::get_coord_fruit()
{
    return frui;
}

void Fruits::set_new_coord_for_fruit()
{
    srand(time(0));
    frui.x = rand() % MAX_ROW;
    frui.y = rand() % MAX_COL;
}