#include "Fruits.h"
#include <cstdlib>
#include <ctime>
Fruits::Fruits()
{
    srand(time(0));
    frui.x = rand() % 13;
    frui.y = rand() % 18;
}

fruit_coord Fruits::get_coord_fruit()
{
    return frui;
}

void Fruits::set_new_coord_for_fruit()
{
    srand(time(0));
    frui.x = rand() % 13;
    frui.y = rand() % 18;
}