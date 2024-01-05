#include "Position.h"

Position::Position(int x, int y) : d_x{ x }, d_y{ y }
{
    //dtor
}

Position::~Position()
{
    //dtor
}

int Position::x() {
    return d_x;
}

int Position::y() {
    return d_y;
}
