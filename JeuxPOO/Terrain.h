#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Cases.h"
#include "goto_xy_windows.h"
#include <vector>
#include "Aventurier.h"
#include "Vide.h"
#include "Sortie.h"
#include "VideC.h"
#include "MonstreV.h"
#include "MonstreA.h"
#include "MonstreA.h"
#include "Pieces.h"
#include "Sortie.h"
#include "Amullette.h"
#include "Mur.h"
#include<fstream>
#include<algorithm>

class Aventurier;
class MonstreV; 
class MonstreA;

using namespace std;

class Terrain {
public:
    Terrain();
    Terrain(int h, int l);
    void afficheTerrain()const;
    void litTerrain();
    void litTerrain(const string& nomF);
    void ecritTerrain() const;
    void ecritTerrain(const string& nomF)const;
    void remplaceCase(Cases& ancienneCase);
    unique_ptr<Cases> retourneCase(int x, int y) const;
    void retourne() const;
    Cases& retourneC(int x, int y);
    Aventurier* trouverAventurier();
    vector<MonstreV*> trouverMonstreV();
    vector<MonstreA*> trouverMonstreA();
    Sortie* trouverSortie();
    Amullette* trouverAmullette();
    vector<Pieces*> trouverPieces();

private:
    int d_h, d_l;
    vector<unique_ptr<Cases>> d_cases;
    
};

#endif // TERRAIN_H_INCLUDED

