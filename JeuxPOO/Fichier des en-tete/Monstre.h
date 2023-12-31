#ifndef MONSTRE_H
#define MONSTRE_H
#include "Personnage.h"
#include "Aventurier.h"

class Monstre : public Personnage
{
public:
    Monstre(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
    void attaquer(const Aventurier& A) const;
    virtual ~Monstre();

protected:

private:
    int d_pourcentageHabilete;
};

#endif // MONSTRE_H
