#include "Epee.h"

Epee::Epee() : Equipement{0}
{
    //ctor
}

Epee::Epee(int pointDeSolidite) : Equipement{ pointDeSolidite }
{
    //ctor
}

string Epee::typeEquipement() const
{
    return "Epee";
}

Epee::~Epee()
{
    // Impl�mentation du destructeur virtuel
}


