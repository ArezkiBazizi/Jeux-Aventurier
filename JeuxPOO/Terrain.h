#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "cases.h"
#include "goto_xy_windows.h"
#include <vector>
#include<fstream>

using namespace std;

class Terrain {
public:
    Terrain();
    Terrain(int h, int l);
    Terrain(int h, int l, const vector<cases>& cases);
    void remplirCases();
    void afficheTerrain()const;
    void litTerrain(const ofstream& ost);
    void ecritTerrain(const ifstream& ist);
private:
    int d_h, d_l;
    vector<cases> d_cases;


};

#endif // TERRAIN_H_INCLUDED

