#include <iostream>
#include <stdlib.h>
#include "Cases.h"
#include "Terrain.h"
#include "Aventurier.h"
#include <conio.h>
#include <windows.h>
#include "Game.h"


using namespace std;

/*void test() {

    Cases A(10, 15, "mur"), B(20, 20, "monster");

    vector<Cases> T;
    T.push_back(A);

    T.push_back(B);

    //cout << "\e[8;1000;100S0t";
    Terrain Ter{ 1000,1000,T };
    //Ter.remplirCases();

    system("cls");
    
    //Ter.ecritTerrain();
    Ter.litTerrain();
    Ter.afficheTerrain();

}

void test2()
{
    vector<Cases> T;

    //cout << "\e[8;1000;100S0t";
    Terrain Ter{ 1000,1000,T };
    //Ter.remplirCases();

    system("cls");

    //Ter.ecritTerrain();
    Ter.litTerrain();
    Ter.afficheTerrain();


    int x{ 2 };
    int y{ 4 };
    Position p{ x,y };
    int v{ 100 };
    int f{ 100 };
    int b{ 0 };

    Aventurier a{ p,v,f,b };
    a.deplacerA(Ter);
    system("cls");
    Ter.afficheTerrain();

}*/

int main() {

    Terrain Ter{ 1000,1000};
    system("cls");
    Game game{ Position{1,1} };
    //Monstre m{Position{1,1},100,100,100 };

 
 }
