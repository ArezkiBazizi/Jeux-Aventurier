#include "Epee.h"

Epee::Epee(int pointDeSolidite) : d_pointDeSolidite{ pointDeSolidite }
{
    //ctor
}

Epee::~Epee()
{
    //dtor
}

virtual string Epee::typeEquipement() const override;
{
    return "Epee";
}

void Equipement::ModifierpointDeSolidite(int Valeur)
{
    d_pointDeSolidite -= Valeur;
}
