#include "Aventurier.h"
#include <locale>

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

