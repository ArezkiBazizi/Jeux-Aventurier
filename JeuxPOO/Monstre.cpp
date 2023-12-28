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
    int i = 0;
    while (i <= A.tabEquipement()[].length())
   {
    if (A.tabEquipement()[i]->typeEquipement() == "Armure") {
        int x = A.tabEquipement()[i]->pointDeSolidite();
        if (x >= d_pourcentageHabilete*3 / 4)
        {
            A.tabEquipement()[i]->ModifierpointDeSolidite(d_pourcentageHabilete * 3 / 4);
            A.encaisser(d_pourcentageHabilete * 1 / 4);
        }
        else
        { 
            A.tabEquipement()[i]->ModifierpointDeSolidite(x);
            A.encaisser(d_pourcentageHabilete - x + d_pourcentageHabilete/4);
        }
    }
    i++;
   }
}


void Monstre::trouverAventurier(const Aventurier& A)
{

}