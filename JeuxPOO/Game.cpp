#include "game.h"


Game::Game(const Position& posAventurier)
{
    bool d_partieEnCours{ true };
    Terrain Ter{ 1000,1000 };
    Ter.litTerrain();

    Aventurier* a = Ter.trouverAventurier();
    vector<MonstreV*> m = Ter.trouverMonstreV();
    Sortie* s = Ter.trouverSortie();
    Amullette* amul = Ter.trouverAmullette();

    Ter.afficheTerrain();
    while (a->estVivant() && d_partieEnCours) {

  
            for (int i = 0; i < m.size(); i++)
            {
                m[i]->trouverAventurier(Ter);
                m[i]->afficheInfoMonstre();
            }
            a->deplacerA(Ter);
            a->afficheInfoAventurier();

            if (a->estSortie() && amul->etatAmullette())
            {
                system("cls");
                Ter.afficheTerrain();
                d_partieEnCours = false;
                cout <<endl << endl << "BRAVO ! Vous avez gagne";
            }
    }
}
			




