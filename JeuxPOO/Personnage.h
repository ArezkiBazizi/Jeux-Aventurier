#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Position.h"
#include "Cases.h"


class Personnage : public Cases
{
public:
    Personnage(const Position& position, int pointDeVie, int pointDeForce);
    void encaisser(int x);
    int pointDeVie() const;
    void modifierPointDeVie(int x);
    int pointDeForce() const;
    void modifierPointDeForce(int x);
    bool estVivant() const;

protected:

private:
    int d_pointDeVie;
    int d_pointDeForce;
};

#endif // PERSONNAGE_H
