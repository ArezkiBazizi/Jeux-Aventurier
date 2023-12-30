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

