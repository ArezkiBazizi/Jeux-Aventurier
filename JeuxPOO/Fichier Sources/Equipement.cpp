#include "Equipement.h"

Equipement::Equipement(int pointDeSolidite) :
    d_pointDeSolidite {poiintDeSolidite}
{

}

void Equipement::ModifierpointDeSolidite(int x)
{
    d_pointDeSolidite -= x;
}

Equipement::~Equipement()
{
    //dtor
}


