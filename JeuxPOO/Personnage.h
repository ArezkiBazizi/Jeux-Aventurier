#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Position.h"


class Personnage
{
public:
    Personnage(const Position& position, int pointDeVie, int pointDeForce);
    void encaisser(int x);
    int pointDeVie() const;
    void modifierPointDeVie(int x);
    int pointDeForce() const;
    void modifierPointDeForce(int x);
    void deplacer(int x,int y);
    bool estVivant() const;
    Position position() const;

protected:

private:
    Position d_position;
    int d_pointDeVie;
    int d_pointDeForce;
};

#endif // PERSONNAGE_H
