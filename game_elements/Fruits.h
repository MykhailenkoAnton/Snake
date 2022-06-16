#pragma once

struct fruit_coord
{
    int x;
    int y;
};

class Fruits
{
protected:
    fruit_coord frui;
public:
    Fruits();
    fruit_coord get_coord_fruit();
    void set_new_coord_for_fruit();
};

