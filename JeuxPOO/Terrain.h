#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Cases.h"
#include "goto_xy_windows.h"
#include <vector>
#include "Personnage.h"
#include<fstream>

using namespace std;

class Terrain {
public:
    Terrain();
    Terrain(int h, int l);
    Terrain(int h, int l, const vector<Cases>& cases);
    void remplirCases();
    void afficheTerrain()const;
    void litTerrain();
    void litTerrain(const string& nomF);
    void ecritTerrain() const;
    void ecritTerrain(const string& nomF)const;
    Cases retourneCase(int x, int y) const;
    Cases& retourneC(int x, int y);

private:
    int d_h, d_l;
    vector<unique_ptr<Cases>> d_cases;


};

#endif // TERRAIN_H_INCLUDED

