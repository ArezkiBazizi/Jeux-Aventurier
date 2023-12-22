// JeuxPOO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Aventurier.h"
#include "Armure.h"
#include <iostream>
#include <memory>


using namespace std;

int main()
{
    Aventurier A{{1,1},100,100,10};
    A.ajouterEquipement(make_unique<Armure>(100));
    cout<<A.pointDeForce();

    return 0;
};