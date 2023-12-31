#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Equipement.h"
#include "Monstre.h"
#include "Terrain.h"
#include <vector>
#include <memory>
#include "Armure.h"
#include "Epee.h"
#include <conio.h>
#include <windows.h>

using namespace std;

class Monstre;

class Aventurier : public Personnage
{
public:
    Aventurier(const Position& position);
    Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces);
    int bourseDePieces() const;
    vector<unique_ptr<Equipement>> const& tabEquipement() const;
    void ajouterEquipement(const string& type, int p);
    virtual ~Aventurier();
    void deplacerA(Terrain& T);
    void Attaquer(Monstre& M);
    bool trouverAllumette(Terrain& T) const;
    void ramasserPieces();
  

protected:

private:
    int d_bourseDePieces;
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
