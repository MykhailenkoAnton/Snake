#include <cstdlib>
#include <ctime>

#include "Fruits.h"

const int MAX_ROW = 13;
const int MAX_COL = 18;
Fruits::Fruits()
{
    srand(time(0));
    _fruit.x = 1 +rand() % MAX_ROW;
    _fruit.y = 1 +rand() % MAX_COL;
}

fruitCoord Fruits::getCoordFruit()
{
    return _fruit;
}

// random fruit coord
void Fruits::setNewCoordForFruit()
{
    srand(time(0));
    _fruit.x = 1 + rand() % MAX_ROW;
    _fruit.y = 1 + rand() % MAX_COL;
}