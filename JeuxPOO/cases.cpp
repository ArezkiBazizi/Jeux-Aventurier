#include "Cases.h"

Cases::Cases(int x, int y) :
    d_x{ x }, d_y{ y }, d_type{}
{
}

Cases::Cases(int x, int y, const string& type) :
    d_x{ x }, d_y{ y }, d_type{ type }
{
}

void Cases::setType(const string& type) {
    d_type = type;
}

int Cases::x()const {
    return d_x;
}

int Cases::y() const {
    return d_y;
}
string Cases::type() const {
    return d_type;
}

bool Cases::estVide()const {
    if (d_type == "vide" || d_type == "videC")
        return true;
    return false;
