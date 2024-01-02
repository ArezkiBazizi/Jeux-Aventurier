#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Position.h"


class Personnage
{
public:
    Personnage(const Position& position, int pointDeVie, int pointDeForce);
    virtual void depalcer();
    void encaisser(int x);
    virtual ~Personnage();

protected:

private:
    Position d_position;
    int d_pointDeVie;
    int d_pointDeForce;
};

#endif // PERSONNAGE_H
