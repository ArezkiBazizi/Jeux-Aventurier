#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include <vector>
#include <memory>
#include "Equipement.h"

using namespace std;

class Aventurier : public Personnage
{
public:
    Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces, vector <unique_ptr<Equipement>> d_tabEquipement);
    Equipement tabEquipement() const;
    virtual ~Aventurier();

protected:

private:
    int d_bourseDePieces;
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
