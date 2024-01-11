#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Cases.h"
#include "goto_xy_windows.h"
#include <vector>
#include "Aventurier.h"
#include "Vide.h"
#include "VideC.h"
#include "MonstreV.h"
#include "MonstreA.h"
#include "Pieces.h"
#include "Amullette.h"
#include "Mur.h"
#include<fstream>

class Aventurier;
class MonstreV; 

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
    unique_ptr<Cases> retourneCase(int x, int y) const;
    void retourne() const;
    std::unique_ptr<Aventurier> retourneAventurier() const;
    Cases& retourneC(int x, int y);

    
private:
    int d_h, d_l;
    vector<unique_ptr<Cases>> d_cases;
    
};

#endif // TERRAIN_H_INCLUDED

