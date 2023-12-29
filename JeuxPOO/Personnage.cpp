#include "Personnage.h"

Personnage::Personnage(const Position& position, int pointDeVie, int pointDeForce) :
    d_position{ position }, d_pointDeVie{ pointDeVie }, d_pointDeForce{ pointDeForce }
{
    //ctor
}

void Personnage::deplacer(int x, int y)
{
    d_position.modifierX(x);
    d_position.modifierY(y);

}

void Personnage::encaisser(int x)
{
    d_pointDeVie -= x;
}

int Personnage::pointDeVie() const
{
    return d_pointDeVie;
}

int Personnage::pointDeForce() const
{
    return d_pointDeForce;
}

bool Personnage::estVivant() const
{
    return (d_pointDeVie > 0);
}

Position Personnage::position() const
{
    return d_position;
}