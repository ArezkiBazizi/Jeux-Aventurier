#include "Epee.h"

Epee::Epee(int pointDeSolidite) : Equipement{ pointDeSolidite }
{
    //ctor
}

Epee::~Epee()
{
    //dtor
}

string Epee::typeEquipement() const override;
{
    return "Epee";
}

void Equipement::ModifierpointDeSolidite(int Valeur)
{
    d_pointDeSolidite -= Valeur;
}
