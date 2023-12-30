#include "Equipement.h"

Equipement::Equipement(int pointDeSolidite) :
    d_pointDeSolidite {pointDeSolidite}
{

}

void Equipement::ModifierpointDeSolidite(int x)
{
    if (d_pointDeSolidite - x/2 >= 0)
    {
        d_pointDeSolidite -= x / 2;
    }
    else 
    {
        d_pointDeSolidite = 0;
    }
}


int Equipement::pointDeSolidite() const
{
    return d_pointDeSolidite;
}
