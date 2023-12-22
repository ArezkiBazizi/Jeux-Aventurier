#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Position.h"


class Personnage
{
public:
    Personnage(const Position& position, int pointDeVie, int pointDeForce);
    void encaisser(int x);
    int pointDeVie() const;
    int pointDeForce() const;
    void deplacer(int x,int y);

protected:

private:
    Position d_position;
    int d_pointDeVie;
    int d_pointDeForce;
};

#endif // PERSONNAGE_H
