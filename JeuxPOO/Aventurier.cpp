#include "Aventurier.h"
#include "Cases.h"
#include "Personnage.h"
#include <cmath>
#include <conio.h>


using namespace std;

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces) :
    Personnage{ position,pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }
{
    d_tabEquipement.push_back(std::make_unique<Armure>(100));

}


Aventurier::~Aventurier()
{
    //dtor
}

std::vector<std::unique_ptr<Equipement>> const& Aventurier::tabEquipement() const
{
    return d_tabEquipement;
}

void Aventurier::ajouterEquipement(unique_ptr<Equipement> e)
{
    d_tabEquipement.push_back(move(e));
}


void Aventurier::deplacer() {
    // Tableau pour stocker l'état des touches de direction
    bool touchesDirection[4] = { false };

    while (_kbhit()) {
        char key = _getch();

        switch (key) {
        case 72: // Flèche vers le haut
            touchesDirection[0] = true;
            break;
        case 80: // Flèche vers le bas
            touchesDirection[1] = true;
            break;
        case 75: // Flèche vers la gauche
            touchesDirection[2] = true;
            break;
        case 77: // Flèche vers la droite
            touchesDirection[3] = true;
            break;
        }
    }

    // Appliquer la logique de déplacement en fonction de l'état des touches
    if (Cases(position().x(), position().y() + 1).estVide()) {
        if (touchesDirection[0]) deplacer(0, 1); // Up
    }
    if (Cases(position().x(), position().y() - 1).estVide()) {
        if (touchesDirection[1]) deplacer(0, -1);  // Down
    }
    if (Cases(position().x() - 1, position().y()).estVide()) {
        if (touchesDirection[2]) deplacer(-1, 0); // Left
    }
    if (Cases(position().x() + 1, position().y()).estVide()) {
        if (touchesDirection[3]) deplacer(1, 0);  // Right
    }








}



void Aventurier::Attaquer(Monstre& M) {
    int i = 0;
    while (d_tabEquipement[i].typeEquipement() == "Epee" || i < d_tabEquipement.length())
        i++;

    if ((abs(M.position().x() - position().x()) = 1) && (abs(M.position().y() - position().y()) = 1))
    {
        M.encaisser(pointDeForce() + d_tabEquipement[i].pointDeSolidite());
    }

    if (d_tabEquipement[i].pointDeSolidite() > 0) {
        d_tabEquipement[i].ModifierpointDeSolidite(-1);
    }
}


}

