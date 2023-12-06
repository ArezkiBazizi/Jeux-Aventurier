#include "Equipement.h"

Equipement::Equipement(int pointDeSolidite) :
    d_pointDeSolidite {poiintDeSolidite}
{

}

Equipement::ModifierpointDeSolidite(int x)
{
    d_pointDeSolidite -= x;
}

Equipement::~Equipement()
{
    //dtor
}


