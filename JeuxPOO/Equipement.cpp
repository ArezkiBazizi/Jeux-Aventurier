#include "Equipement.h"

Equipement::Equipement(int pointDeSolidite) :
    d_pointDeSolidite {pointDeSolidite}
{

}

void Equipement::ModifierpointDeSolidite(int x)
{
    d_pointDeSolidite -= x/2;
}


int Equipement::pointDeSolidite() const
{
    return d_pointDeSolidite;
}
