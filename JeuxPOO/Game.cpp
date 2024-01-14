#include "game.h"


Game::Game(Terrain& Ter)
{
    bool d_partieEnCours{ true };
    Ter.litTerrain();

    Aventurier* a = Ter.trouverAventurier();
    vector<MonstreV*> mv = Ter.trouverMonstreV();
    vector<MonstreA*> ma = Ter.trouverMonstreA();
    Sortie* s = Ter.trouverSortie();
    Amullette* amul = Ter.trouverAmullette();

    Ter.afficheTerrain();
    while (a->estVivant() && d_partieEnCours) {

  
            for (int i = 0; i < mv.size(); i++)
            {
                mv[i]->trouverAventurier(Ter);
                mv[i]->afficheInfoMonstre();
            }

            for (int i = 0; i < ma.size(); i++)
            {
                ma[i]->deplaceAveugle(Ter);
                ma[i]->afficheInfoMonstre();
            }
            a->deplacerA(Ter);
            a->afficheInfoAventurier();

            if (a->estSortie() && amul->etatAmullette())
            {
                system("cls");
                d_partieEnCours = false;
                cout << endl;
                cout << "________________________________________" << endl;
                cout << "|                                       |" << endl;
                cout << "|       BRAVO ! Vous avez gagne         |" << endl;
                cout << "|                                       |" << endl;
                cout << "|_______________________________________|" << endl;

                system("pause = null");
            }
    }
}
			




