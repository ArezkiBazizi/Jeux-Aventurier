#include "Armure.h"


Armure::Armure(int pointDeSolidite) : Equipement{ pointDeSolidite}
{

}

Armure::~Armure()
{
    //dtor
}

string Armure::typeEquipement() const override
{
    return "Armure";
}

int Armure::pointDeSolidite() const override
{
    return d_pointDeSolidite;
}

void Armure::ModifierpointDeSolidite(int Valeur) override
{
    d_pointDeSolidite -= Valeur;
}
