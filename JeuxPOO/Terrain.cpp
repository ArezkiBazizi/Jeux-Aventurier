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
     
        if (d_cases[i].type() == "mur")
            cout << "#";
        else if (d_cases[i].type() == "vide")
            cout << ".";
        else if (d_cases[i].type() == "videC")
            cout << "/";
        else if (d_cases[i].type() == "sortie")
            cout << "+";
        else if (d_cases[i].type() == "monster")
            cout << "M";
        else if (d_cases[i].type() == "allumette")
            cout << "@";
        else if (d_cases[i].type() == "aventurier")
            cout << "A";
        else if (d_cases[i].type() == "pieces")
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


void Terrain::ecritTerrain(const string& nomF) const {

    ofstream f(nomF);
    for (int i = 0; i < d_cases.size(); i++) {
        f << d_cases[i].x() << " " << d_cases[i].y() << " " << d_cases[i].type() << endl;
    }


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
        d_cases.push_back(Cases{ x,y,t });
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
        if (d_cases[i].x() == x && d_cases[i].y() == y)
        {
            return d_cases[i];
        }
        else 
        {
            i++;
        }
    }
    return  d_cases[i];
}
 

void Terrain::rafraichirTerrain(const Personnage& a)
{
    int i = 0;
    while (i < d_cases.size())
    {
        if (d_cases[i].type() == "aventurier")
        {

            Cases c = retourneCase(a.position().x(), a.position().y());
            c.setType("vide");

            d_cases[i].x(a.position().x());
            d_cases[i].y(a.position().y());

        }
        i++;
    }

}

