#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Equipement.h"
#include "Monstre.h"
#include "Terrain.h"
#include "Pieces.h"
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
    virtual ~Aventurier();
    int bourseDePieces() const;
    vector<unique_ptr<Equipement>> const& tabEquipement() const;
    void ajouterEquipement(const string& type, int p);
    void deplacerA(Terrain& T);
    void Attaquer(Monstre& M);
    bool ramasserAllumette(Terrain& T) const;
    bool ramasserPieces(Pieces& P);
    bool estSortie(Terrain& T) const;
    string type() const override;
  

protected:

private:
    int d_bourseDePieces;
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
