#pragma once
const int ROWS = 15;
const int COLUMNS = 20;
const int MAX_SIZE_FIELD = 40;
class Field
{
private:
    char FIELD[ROWS][COLUMNS];
public:
    void fill_field_by_coord();
    void draw_field();
};

