#include "Position.h"

Position::Position(int x, int y) : d_x{x}, d_y{y}
{
    //dtor
}

Position::~Position()
{
    //dtor
}

int Position::x() const {
    return d_x;
}

int Position::y() const {
    return d_y;
}
void Position::modifierX(int x)
{
    d_x += x;
}
void Position::modifierY(int y)
{
    d_y += y;
}
