#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Monstre.h"
#include <vector>
#include <memory>
#include "Armure.h"

using namespace std;

class Aventurier : public Personnage
{
public:
    Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces);
    int bourseDePieces() const;
    vector<unique_ptr<Equipement>> const& tabEquipement() const;
    void ajouterEquipement(unique_ptr<Equipement> e);
    virtual ~Aventurier();
    void deplacerA();
    void Attaquer(Monstre& M);
    bool trouverAllumette() const;
    void ramasserPieces();
  

protected:

private:
    int d_bourseDePieces;
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
