#include "Terrain.h"


Terrain::Terrain() :
    d_h{ 0 }, d_l{ 0 }, d_cases{}
{
}

Terrain::Terrain(int h, int l) :
    d_h{ h }, d_l{ l }, d_cases{}
{}

Terrain::Terrain(int h, int l, const vector<Cases>& cases) :
    d_h{ h }, d_l{ l }, d_cases{ cases }
{
}

void Terrain::afficheTerrain()const {
    for (int i = 0; i < d_cases.size(); i++) {
        goto_xy(d_cases[i].x(), d_cases[i].y());
        /* switch(d_cases[i].type()){
             case mur : cout << "#"; break;
             case vide : cout << "/"; break;
             case videC : cout << "."; break;
             case sortie : cout << "+"; break;
             case monster : cout << "M"; break;
             case allumette : cout << "@"; break;
             case aventurier : cout << "A"; break;
             default : break;
         }*/
        if (d_cases[i].type() == "mur")
            cout << "#";
        else if (d_cases[i].type() == "vide")
            cout << "/";
        else if (d_cases[i].type() == "videC")
            cout << ".";
        else if (d_cases[i].type() == "sortie")
            cout << "+";
        else if (d_cases[i].type() == "monster")
            cout << "M";
        else if (d_cases[i].type() == "allumette")
            cout << "@";
        else if (d_cases[i].type() == "aventurier")
            cout << "A";
        else if (d_cases[i].type() == "piece")
            cout << "P";
    }
}


void Terrain::remplirCases() {
    string a;
    do {
        int x, y;

        cout << "Entrer la case x , y et le type de case (saisir 0 en type pour fin)" << endl;
        cin >> x >> y >> a;
        if (a != "0") {
            d_cases.push_back(Cases{ x,y,a });
        }

    } while (a != "0");
}


void Terrain::ecritTerrain(const ifstream& ist) {

}

Cases Terrain::retourneCase(int x, int y) const

{
    while (i < d_case.size())
    {
        if (d_case[i].x() == x && d_case[i].y() == y)
        {
            return d_case[i];
            i = d_case.size();
        }
        else 
        {
            i++;
        }
    }
}
