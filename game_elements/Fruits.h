#pragma once

struct fruitCoord
{
    int x;
    int y;
};

class Fruits
{
protected:
    fruitCoord _fruit;
public:
    Fruits();
    fruitCoord getCoordFruit();
    void setNewCoordForFruit();
};

