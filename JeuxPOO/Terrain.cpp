#include "Terrain.h"


Terrain::Terrain() :
    d_h{ 0 }, d_l{ 0 }, d_cases{}
{
}

Terrain::Terrain(int h, int l) :
    d_h{ h }, d_l{ l }, d_cases{}
{
    litTerrain();
}


void Terrain::afficheTerrain()const {
    for (int i = 0; i < d_cases.size()-1; i++) {
        goto_xy(d_cases[i]->position().x(), d_cases[i]->position().y());
     
        if (d_cases[i]->type() == "Mur")
            cout << "#";
        else if (d_cases[i]->type() == "Vide")
            cout << ".";
        else if (d_cases[i]->type() == "VideC")
            cout << "/";
        else if (d_cases[i]->type() == "Sortie")
            cout << "+";
        else if (d_cases[i]->type() == "Monster")
            cout << "M";
        else if (d_cases[i]->type() == "Allumette")
            cout << "@";
        else if (d_cases[i]->type() == "Aventurier")
            cout << "A";
        else if (d_cases[i]->type() == "Pieces")
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
        if (t == "Vide")
        {
            d_cases.push_back(make_unique<Vide>(x, y));
        }
        else if (t == "VideC")
        {
            d_cases.push_back(make_unique<VideC>(x, y));
        }
        else if (t == "Aventurier")
        {
            d_cases.push_back(make_unique<Aventurier>( Position{x,y}));
        }
        else if (t == "MonstreV")
        {
           // d_cases.push_back(make_unique<MonstreV>(Position{ x,y },100, 100, 100));
        }

    }
}

void Terrain::litTerrain() {
    litTerrain("map.txt");
}

std::unique_ptr<Cases> Terrain::retourneCase(int x, int y) const
{
    for (const auto& casePtr : d_cases)
    {
        if (casePtr->position().x() == x && casePtr->position().y() == y)
        {
            return std::make_unique<Cases>(*casePtr); // Retourne une nouvelle instance copiée
        }
    }

    return nullptr; // Retourne un pointeur unique vide si aucune case correspondante n'est trouvée
}


void Terrain::retourne() const
{
    for (int i = 0; i < d_cases.size(); i++)
    {
        cout << d_cases[i]->type()<<endl;
    }
    
}