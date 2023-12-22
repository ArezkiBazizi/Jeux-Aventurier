#include "Armure.h"


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

