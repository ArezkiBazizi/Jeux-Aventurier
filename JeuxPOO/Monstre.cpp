#include "Monstre.h"

Monstre::Monstre(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) :
    Personnage{ position,pointDeVie,pointDeForce }, d_pourcentageHabilete{ pourcentageHabilete }
{
    //ctor
}


Monstre::~Monstre()
{
    //dtor
}

int Monstre::obtenirPourcentageHabilete() const
{
    return d_pourcentageHabilete;
}

void Monstre::attaquer(Aventurier& A) const
{

    if (A.tabEquipement()[0]->typeEquipement() == "Armure") {
        int x = A.tabEquipement()[0]->pointDeSolidite();
        A.encaisser(x);
    }
    else if (A.tabEquipement()[1]->typeEquipement() == "Armure") {
        int x = A.tabEquipement()[1]->pointDeSolidite();
        A.encaisser(x);
    }
}

