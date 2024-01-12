#include "Cases.h"

Cases::Cases(int x, int y) :

    d_position{ Position{x,y} }
{
}

Cases::Cases(const Position& position) : d_position{position}
{

}

string Cases::type() const
{
    return "Cases";
}



void Cases::switchCases(Cases& c)
{
    Position aux(0,0);
    aux.modifierX(c.position().x());
    aux.modifierY(c.position().y());
    c.setPosition(d_position);
    setPosition(aux);

}

void Cases::setPosition(const Position& p) {
    d_position = p;
}

Position Cases::position() const
{
    return d_position;
}

void Cases::deplacer(int x, int y)
{
    d_position.modifierX(x);
    d_position.modifierY(y);
}

Cases& Cases::operator=(const Cases& c) {
    if (this != &c) {
        d_position = c.d_position;
    }
    return *this;
}

bool Cases::operator==(const Cases& other) const {
    return (position().x() == other.position().x()) && (position().y() == other.position().y());
}