// JeuxPOO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
//#include "Aventurier.h"
//#include "Armure.h"
#include "Cases.h"
#include "Terrain.h"
#include <iostream>
//#include <memory>


using namespace std;

void test() {

    Cases A(10, 15, "mur"), B(20, 20, "monster");

    vector<Cases> T;
    T.push_back(A);

    T.push_back(B);

    cout << "\e[8;50;100t";
    Terrain Ter{ 100,100,T };
    Ter.remplirCases();

    system("cls");
    Ter.afficheTerrain();

}

int main()
{
    /*Aventurier A{{1,1},100,100,10};
    A.ajouterEquipement(make_unique<Armure>(100));
    cout<<A.pointDeForce();
    */
    test();
    return 0;
};