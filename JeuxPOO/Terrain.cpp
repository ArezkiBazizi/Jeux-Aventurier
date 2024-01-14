#include "Terrain.h"


Terrain::Terrain() :
    d_h{ 0 }, d_l{ 0 }, d_cases{}
{
}

Terrain::Terrain(int h, int l) :
    d_h{ h }, d_l{ l }, d_cases{}
{
    
}


void Terrain::afficheTerrain()const {
    for (int i = 0; i < d_cases.size(); i++) {
        goto_xy(d_cases[i]->position().x(), d_cases[i]->position().y());
     
        if (d_cases[i]->type() == "Mur")
            cout << "#";
        else if (d_cases[i]->type() == "Vide")
            cout << ".";
        else if (d_cases[i]->type() == "VideC")
            cout << "/";
        else if (d_cases[i]->type() == "Sortie")
            cout << "+";
        else if (d_cases[i]->type() == "MonstreV")
            cout << "M";
        else if (d_cases[i]->type() == "MonstreA")
            cout << "m";
        else if (d_cases[i]->type() == "Amullette")
            cout << "@";
        else if (d_cases[i]->type() == "Aventurier")
            cout << "A";
        else if (d_cases[i]->type() == "Pieces")
            cout << "P";
    }
}



void Terrain::ecritTerrain(const string& nomF) const {

    ofstream f(nomF, ofstream::trunc);
    for (int i = 0; i < d_cases.size(); i++) {

        f << d_cases[i]->position().x() << " " << d_cases[i]->position().y() << " " << d_cases[i]->type() << endl;
    }
    f.close();

}

void Terrain::ecritTerrain()const {
    ecritTerrain("map.txt");
}


void Terrain::litTerrain(const string& nomF) {
    ifstream f(nomF, fstream::in);
    int  x =0 , y=0;
    char t;
    d_cases.clear();
    while (f >> noskipws >> t) {
        if (t == '#') {
            d_cases.push_back(make_unique<Mur>(Position{ x,y }));
        }
        else if (t == '.') {
            d_cases.push_back(make_unique<Vide>(x, y));
        }
        else if (t == '/') {
            d_cases.push_back(make_unique<VideC>(x, y));
        }
        else if (t == 'A') {
            d_cases.push_back(make_unique<Aventurier>(Position{ x, y }));
        }
        else if (t == '@') {
            d_cases.push_back(make_unique<Amullette>(Position{ x,y }));
        }
        else if (t == 'M') {
            d_cases.push_back(make_unique<MonstreV>(Position{ x, y }, 100, 100, 100));
        }
        else if (t == 'm') {
            d_cases.push_back(make_unique<MonstreA>(Position{ x, y }, 100, 100, 100));
        }
        else if (t == '+') {
            d_cases.push_back(make_unique<Sortie>(x, y));
        }
        else if (t == 'P') {
            d_cases.push_back(make_unique<Pieces>(20, Position{ x,y }));
        }
        x++;
        if (t == '\n') {
            y++;
            x = 0;
        }
    }
   


}

void Terrain::litTerrain() {
    litTerrain("map.txt");
}



void Terrain::creerTerrain(const string& nomF)  {
    ofstream f(nomF);
    string line;
    int i = 1;
    while (line != "0") {
        cout << "Entrer la ligne numero et tapez Entrer pour rentrer la ligne suivante " << i << " (Entrez 0 pour terminer la creation du terrain)" << endl;
        cin >> line;
        f << line << endl;
        i++;
    }

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
        cout << d_cases[i]->type()<< " "  << d_cases[i]->position().x() << " " << d_cases[i]->position().y() << endl;
    }
    
}

Aventurier* Terrain::trouverAventurier() {
    for (auto& c : d_cases) {
        Aventurier* aventurier = dynamic_cast<Aventurier*>(c.get());
        if (aventurier) {
            return aventurier;
        }
    }
    return nullptr;
}

vector<MonstreV*> Terrain::trouverMonstreV() {
    vector<MonstreV*> d_monstre;
    for (auto& c : d_cases) {
        MonstreV* monstre = dynamic_cast<MonstreV*>(c.get());
        if (monstre) {
            d_monstre.push_back(monstre);
        }
    }
    return d_monstre;
}

vector<MonstreA*> Terrain::trouverMonstreA() {
    vector<MonstreA*> d_monstre;
    for (auto& c : d_cases) {
        MonstreA* monstre = dynamic_cast<MonstreA*>(c.get());
        if (monstre) {
            d_monstre.push_back(monstre);
        }
    }
    return d_monstre;
}

vector<Pieces*> Terrain::trouverPieces() {
    vector<Pieces*> d_pieces;
    for (auto& c : d_cases) {
        Pieces* pieces = dynamic_cast<Pieces*>(c.get());
        if (pieces) {
            d_pieces.push_back(pieces);
        }
    }
    return d_pieces;
}

Sortie* Terrain::trouverSortie() {
    for (auto& c : d_cases) {
        Sortie* sortie = dynamic_cast<Sortie*>(c.get());
        if (sortie) {
            return sortie;
        }
    }
    return nullptr;
}

Amullette* Terrain::trouverAmullette() {
    for (auto& c : d_cases) {
        Amullette* amul = dynamic_cast<Amullette*>(c.get());
        if (amul) {
            return amul;
        }
    }
    return nullptr;
}


Cases& Terrain::retourneC(int x, int y) {
    // Parcourez les cases existantes pour trouver la case correspondante.
    for (auto& c : d_cases) {
        if (c->position().x() == x && c->position().y() == y) {
            return *c; // Renvoie la case existante avec les coordonnées correspondantes.
        }
        
    }

    // Si aucune case correspondante n'est trouvée, lancez une exception ou faites ce qui est approprié pour votre programme.
    throw std::runtime_error("Case non trouvée pour les coordonnées");
}


void Terrain::remplaceCase(Cases& ancienneCase) {
    std::for_each(d_cases.begin(), d_cases.end(), [&ancienneCase](unique_ptr<Cases>& casePtr) {

        if (*casePtr == ancienneCase) {

            casePtr = std::make_unique<Vide>(ancienneCase.position().x(), ancienneCase.position().y());
        }
        });
}