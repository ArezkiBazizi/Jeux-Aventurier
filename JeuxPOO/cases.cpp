#include "Cases.h"

Cases::Cases(int x, int y) :

    d_position{ Position{x,y} }
{
}

Cases::Cases(const Position& position) : d_position{position}
{

}


Position Cases::position() const
{
    return d_position;
}


void Cases::x(int x) {
    d_x = x;
}

void Cases::y(int y) {
    d_y = y;
}
