#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//#include "Aventurier.h"
//#include "Armure.h"
#include "Cases.h"
#include "Terrain.h"
//#include <iostream>
//#include <memory>

void test() {

    Cases A(10, 15, "mur"), B(20, 20, "monster");

    vector<Cases> T;
    T.push_back(A);

    T.push_back(B);

    //cout << "\e[8;50;100t";
    Terrain Ter{ 100,100,T };
    Ter.remplirCases();

    system("cls");
    Ter.afficheTerrain();

}

void mainTest()
{
   
}