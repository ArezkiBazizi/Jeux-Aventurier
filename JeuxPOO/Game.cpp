#include "game.h"


Game::Game(Terrain& Ter)
{
    system("cls");
    bool d_partieEnCours{ true };
   
   
   

    Ter.afficheTerrain();


    Aventurier* a = Ter.trouverAventurier();
    vector<MonstreV*> mv = Ter.trouverMonstreV();
    vector<MonstreA*> ma = Ter.trouverMonstreA();
    Sortie* s = Ter.trouverSortie();
    Amullette* amul = Ter.trouverAmullette();

    Ter.afficheTerrain();
    while (a->estVivant() && d_partieEnCours) {

             a->afficheInfoAventurier();

            for (int i = 0; i < mv.size(); i++)
            {
                if(abs(a->position().x()-mv[i]->position().x()) <= 3 && abs(a->position().y() - mv[i]->position().y()) <=3)
                    mv[i]->afficheInfoMonstre(i);

                mv[i]->trouverAventurier(Ter);

            }

            for (int i = 0; i < ma.size(); i++)
            {
                if (abs(a->position().x() - mv[i]->position().x()) <= 3 && abs(a->position().y() - mv[i]->position().y()) <= 3)
                    mv[i]->afficheInfoMonstre(i);

                ma[i]->deplaceAveugle(Ter);

            }
            a->deplacerA(Ter);


            if (a->estSortie()){
                if (amul->etatAmullette())
                {
                    system("cls");
                    d_partieEnCours = false;
                    cout << endl;
                    cout << "________________________________________" << endl;
                    cout << "|                                       |" << endl;
                    cout << "|       BRAVO ! Vous avez gagne         |" << endl;
                    cout << "|                                       |" << endl;
                    cout << "|_______________________________________|" << endl;

                    system("pause > null");
                }
                else {
                    system("cls");
                    d_partieEnCours = false;
                    cout << endl;
                    cout << "________________________________________" << endl;
                    cout << "|                                       |" << endl;
                    cout << "|     PERDU ! Vous avez oublier         |" << endl;
                    cout << "|      de recuperer l'amullette         |" << endl;
                    cout << "|_______________________________________|" << endl;

                    system("pause > null");

                }
            }
    }

    if (!a->estVivant() && d_partieEnCours)
    {
        system("cls");
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|                                       |" << endl;
        cout << "|       PERDU ! VOUS ETES MORT          |" << endl;
        cout << "|                                       |" << endl;
        cout << "|_______________________________________|" << endl;
    }

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
			




