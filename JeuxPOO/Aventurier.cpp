#include "Aventurier.h"
#include <cmath>
#include <conio.h>
#include<windows.h> 


using namespace std;

Aventurier::Aventurier(const Position& position) :
    
    Personnage{position,100,100}, d_bourseDePieces{0}
{
    d_tabEquipement.push_back(make_unique<Armure>(100));
    d_tabEquipement.push_back(make_unique<Epee>(100));
}

string Aventurier::type() const
{
    return "Aventurier";
}

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces, int PointDeSoliditeArmure, int PointDeSoliditeEpee) :
    Personnage{position,pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }
{
    d_tabEquipement.push_back(std::make_unique<Armure>(PointDeSoliditeArmure));
    d_tabEquipement.push_back(std::make_unique<Epee>(PointDeSoliditeEpee));
}


Aventurier::~Aventurier()
{
    //dtor
}

int Aventurier::bourseDePieces() const {
    return d_bourseDePieces;
}

std::vector<std::unique_ptr<Equipement>> Aventurier::tabEquipement() const
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
    
    char ch;
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
            if (T.retourneCase(position().x(), position().y() + 1)->type() == "Vide" ) {
           
                deplacer(0, 1); // Up

            }
        }
        if (touchesDirection[1])
        {
        if (T.retourneCase(position().x(), position().y() - 1)->type() == "Vide") {
            
                
                deplacer(0, -1);  // Down
                


            }
        }
        if (touchesDirection[2])
        {
            if (T.retourneCase(position().x() - 1, position().y())->type() == "Vide") {
            
               
                deplacer(-1, 0); // Left
                


            }
        }
        if (touchesDirection[3])
        {
            if (T.retourneCase(position().x() + 1, position().y())->type() == "Vide") {
            
                
                deplacer(1, 0);  // Right
               

            }
        }
        
        system("cls");
        T.ecritTerrain();
        //T.litTerrain();
        T.afficheTerrain();


    //cout << b.type() << endl;
}

void Aventurier::Attaquer(Monstre& M) {
    int i = 0;
    while (i < d_tabEquipement.size() && d_tabEquipement[i]->typeEquipement() != "Epee")
        i++;

    if ((M.position().x() == position().x()) && (M.position().y() == position().y()))
    {
        M.encaisser(pointDeForce() + d_tabEquipement[i]->pointDeSolidite());
        if (M.pointDeVie() < 0)
            M.modifierPointDeVie(0);
    }

    if (d_tabEquipement[i]->pointDeSolidite() > 0) {
        d_tabEquipement[i]->setPointDeSolidite(d_tabEquipement[i]->pointDeSolidite()-1);
    }

    if (!M.estVivant()) {
        modifierPointDeForce(pointDeForce()+ static_cast<int>(0.25 * M.pointDeForce()));
        modifierPointDeVie(pointDeVie()+ static_cast<int>(0.75 * M.pointDeForce()));
    }

}

bool Aventurier::ramasserAllumette(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y())->type() == "allumette");
}


bool Aventurier::ramasserPieces(Pieces& P) {
    if (P.position().x() - position().x() == 0 && P.position().y() - position().y() == 0) {
        d_bourseDePieces += P.valeur();
        return true;
    }
    else return false;

}

bool Aventurier::estSortie(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y())->type() == "sortie");
}