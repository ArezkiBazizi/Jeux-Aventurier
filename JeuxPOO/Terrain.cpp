#include "Terrain.h"


Terrain::Terrain() :
    d_h{ 0 }, d_l{ 0 }, d_cases{}
{
}

Terrain::Terrain(int h, int l) :
    d_h{ h }, d_l{ l }, d_cases{}
{}

Terrain::Terrain(int h, int l, const vector<unique_ptr<Cases>>& cases) :
    d_h{ h }, d_l{ l }, d_cases{}
{
    
}

void Terrain::afficheTerrain()const {
    for (int i = 0; i < d_cases.size()-1; i++) {
        goto_xy(d_cases[i]->position().x(), d_cases[i]->position().y());
     
        if (d_cases[i]->type() == "mur")
            cout << "#";
        else if (d_cases[i]->type() == "vide")
            cout << ".";
        else if (d_cases[i]->type() == "videC")
            cout << "/";
        else if (d_cases[i]->type() == "sortie")
            cout << "+";
        else if (d_cases[i]->type() == "monster")
            cout << "M";
        else if (d_cases[i]->type() == "allumette")
            cout << "@";
        else if (d_cases[i]->type() == "aventurier")
            cout << "A";
        else if (d_cases[i]->type() == "pieces")
            cout << "P";
    }
}





void Terrain::ecritTerrain(const string& nomF) const {

    ofstream f(nomF, ofstream::trunc);
    for (int i = 0; i < d_cases.size()-1; i++) {

        f << d_cases[i]->position().x() << " " << d_cases[i]->position().y() << " " << d_cases[i]->type() << endl;
    }
    f.close();

}

void Terrain::ecritTerrain()const {
    ecritTerrain("map.txt");
}

void Terrain::litTerrain(const string& nomF) {
    ifstream f(nomF);
    int x, y;
    string t;
    d_cases.clear();
    while (f) {
        f >> x >> y >> t;
        d_cases.push_back(make_unique<Cases>( x,y ));
    }
}

void Terrain::litTerrain() {
    litTerrain("map.txt");
}


Cases Terrain::retourneCase(int x, int y) const

{
    int i=0;
    while (i < d_cases.size())
    {
        if (d_cases[i]->position().x() == x && d_cases[i]->position().y() == y)
        {
            return *d_cases[i];
        }
        else 
        {
            i++;
        }
    }
    return  *d_cases[i];
}





