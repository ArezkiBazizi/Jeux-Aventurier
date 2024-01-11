#include "Armure.h"


Armure::Armure() : Equipement{0}
{

}

Armure::Armure(int pointDeSolidite) : Equipement{ pointDeSolidite}
{

}

std::string Armure::typeEquipement() const
{
    return "Armure";
}

Armure::~Armure()
{

}

void Armure::ModifierpointDeSolidite(int x)
{
    if (pointDeSolidite() - x / 2 >= 0)
    {
        setPointDeSolidite( pointDeSolidite() - x / 2);
    }
    else
    {
        setPointDeSolidite (0);
    }
}

