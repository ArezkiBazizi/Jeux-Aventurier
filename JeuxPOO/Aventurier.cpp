#include "Aventurier.h"

#include <cmath>
#include <conio.h>


using namespace std;

Aventurier::Aventurier(const Position& position) :
    
    Personnage{Cases{position},100,100}, d_bourseDePieces{0}
{
 
}

string Aventurier::type() const
{
    return "Aventurier";
}

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces) :
    Personnage{Cases{position},pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }
{
    d_tabEquipement.push_back(std::make_unique<Armure>(100));
    d_tabEquipement.push_back(std::make_unique<Epee>(100));
}


Aventurier::~Aventurier()
{
    //dtor
}

int Aventurier::bourseDePieces() const {
    return d_bourseDePieces;
}

std::vector<std::unique_ptr<Equipement>> const& Aventurier::tabEquipement() const
{
    return d_tabEquipement;
}

void Aventurier::ajouterEquipement(const string& type, int p)
{
 
        if (type == "Epee")
        {
            d_tabEquipement.push_back(std::make_unique<Epee>(p));
        }
        else if (type == "Armure")
        {
            d_tabEquipement.push_back(std::make_unique<Armure>(p));
        }
}


void Aventurier::deplacerA( Terrain& T) {
    // Tableau pour stocker l'état des touches de direction
    bool touchesDirection[4];

    for (int i = 0; i < 4; i++)
    {
        touchesDirection[i] = false;
    }

      
        int flag = 1;

        while (flag) {
            if (GetKeyState(VK_UP) & 0x8000) {
                touchesDirection[0] = true;
                flag = 0;
            }
            if (GetKeyState(VK_DOWN) & 0x8000) {
                touchesDirection[1] = true;
                flag = 0;
            }
            if (GetKeyState(VK_LEFT) & 0x8000) {
                touchesDirection[2] = true;
                flag = 0;
            }
            if (GetKeyState(VK_RIGHT) & 0x8000) {
                touchesDirection[3] = true;
                flag = 0;
            }

        }



        // Appliquer la logique de déplacement en fonction de l'état des touches
        if (touchesDirection[0])
        {
        if (T.retourneCase(position().x(), position().y() + 1).estVide()) {
           
                T.retourneC(position().x(), position().y()).setType("vide");
                deplacer(0, 1); // Up
                T.retourneC(position().x(), position().y()).setType("aventurier");



            }
        }
        if (touchesDirection[1])
        {
        if (T.retourneCase(position().x(), position().y() - 1).estVide()) {
            
                T.retourneC(position().x(), position().y()).setType("vide");
                deplacer(0, -1);  // Down
                T.retourneC(position().x(), position().y()).setType("aventurier");


            }
        }
        if (touchesDirection[2])
        {
            if (T.retourneCase(position().x() - 1, position().y()).estVide()) {
            
                T.retourneC(position().x(), position().y()).setType("vide");
                deplacer(-1, 0); // Left
                T.retourneC(position().x(), position().y()).setType("aventurier");


            }
        }
        if (touchesDirection[3])
        {
            if (T.retourneCase(position().x() + 1, position().y()).estVide()) {
            
                T.retourneC(position().x(), position().y()).setType("vide");
                deplacer(1, 0);  // Right
                T.retourneC(position().x(), position().y()).setType("aventurier");




            }
        }

        system("cls");
        T.ecritTerrain();
        T.afficheTerrain();


    //cout << b.type() << endl;
}

void Aventurier::Attaquer(Monstre& M) {
    int i = 0;
    while (i < d_tabEquipement.size() && d_tabEquipement[i]->typeEquipement() != "Epee")
        i++;

    if ((abs(M.position().x() - position().x()) == 1) && (abs(M.position().y() - position().y()) == 1))
    {
        M.encaisser(pointDeForce() + d_tabEquipement[i]->pointDeSolidite());
    }

    if (d_tabEquipement[i]->pointDeSolidite() > 0) {
        d_tabEquipement[i]->ModifierpointDeSolidite(-1);
    }

    if (!M.estVivant()) {
        modifierPointDeForce(pointDeForce()+ static_cast<int>(0.25 * M.pointDeForce()));
        modifierPointDeVie(pointDeForce()+ static_cast<int>(0.75 * M.pointDeForce()));
    }

}

bool Aventurier::ramasserAllumette(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y()).type() == "allumette");
}


bool Aventurier::ramasserPieces(Pieces& P) {
    if (P.position().x() - position().x() == 0 && P.position().y() - position().y() == 0) {
        d_bourseDePieces += P.valeur();
        return true;
    }
    else return false;

}

bool Aventurier::estSortie(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y()).type() == "sortie");
}