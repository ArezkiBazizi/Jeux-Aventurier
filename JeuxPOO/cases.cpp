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
