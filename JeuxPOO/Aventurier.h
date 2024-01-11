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
    Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces, int PointDeSoliditeArmure, int PointDeSoliditeEpee);
    ~Aventurier();
    int bourseDePieces() const;
    const vector<unique_ptr<Equipement>>& tabEquipement() const;
    void deplacerA(Terrain& T);
    void Attaquer(Monstre& M);
    bool TrouverAllumette(Terrain& T) const;
    void ramasserPieces(Pieces& P, Terrain& T);
    bool estSortie(Terrain& T) const;
    string type() const override;
    void afficheInfoAventurier();
  

protected:

private:
    int d_bourseDePieces;
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
