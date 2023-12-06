#include "Aventurier.h"

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces, vector <unique_ptr<Equipement>> tabEquipement) :
    Personnage{ position,pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }, d_tabEquipement{ tabEquipement }
{
    //ctor
}

Aventurier::~Aventurier()
{
    //dtor
}
