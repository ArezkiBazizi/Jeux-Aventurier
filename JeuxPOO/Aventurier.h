#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Equipement.h"
#include "Amullette.h"
#include "Monstre.h"
#include "Sortie.h"
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
    void ramasserAmullette(Terrain& ,Cases& C);
    void ramasserPieces(Pieces& P, Terrain& T);
    string type() const override;
    void afficheInfoAventurier();
    void combat(Cases& c, Terrain& T);
    void sortir(Terrain& T, Cases& C);
    bool estSortie() const;
  

protected:

private:
    int d_bourseDePieces;
    bool d_sortir{ false };
    vector<unique_ptr<Equipement>> d_tabEquipement;
};

#endif // AVENTURIER_H
