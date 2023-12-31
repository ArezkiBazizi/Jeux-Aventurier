#include "Personnage.h"

Personnage::Personnage(const Position& position, int pointDeVie, int pointDeForce) :
    d_position{ position }, d_pointDeVie{ pointDeVie }, d_pointDeForce{ pointDeForce }
{
    //ctor
}

Personnage::~Personnage()
{
    //dtor
}

void Personnage::encaisser(int x)
{
    d_pointDeVie -= x;
}

