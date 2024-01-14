#include <iostream>
#include <stdlib.h>
#include "Terrain.h"
#include "Game.h"


using namespace std;


int main() {
    int choice;
    std::string filename;
    Terrain T{ 1000, 1000 };

    do {
        std::cout << "\n Menu :\n"
            << "1. Jouer avec un terrain par default\n"
            << "2. Creer un terrain et le sauvegarder\n"
            << "3. Charger la configuration d'un terrain\n"
            << "0. Quitter\n"
            << "Choix : ";
        std::cin >> choice;

        switch(choice){
        case 1:
            T.litTerrain();
            Game{ T };
            cout << "1. Rejouer " << endl;
            cout << "0. Sortir le Menu" << endl;
            cout << endl << flush;
            cin >> choice;
            switch (choice)
            {
            case 1:
                Game{ T };
                break;
            case 0:
                system("cls");
                break;
            }

            break;
        case 2:
            cout << "Entrez le nom du terrain (terrain.txt)" << endl;
            cin >> filename;
            T.creerTerrain(filename);
            cout << "1. Organiser une partie de jeu avec le nouveau terrain creer\n";
            cout << "0. Sauvegarder le terrain et quitter\n";
            cin >> choice;
            switch(choice)
            {   
                case 1:
                    T.litTerrain(filename);
                    Game{ T };
                    break;
                case 0: 
                    std::cout << "Au revoir !" << std::endl;
                    break;
            }
            break;
        case 3:
            cout << "Entrez le nom du fichier à charger : ";
            cin >> filename;
            T.litTerrain(filename);
            cout << "1. Organiser une partie de jeu avec le terrain\n";
            cout << "2. Editer ce terrain\n";
            cout << "0. Quitter\n";
            cin >> choice;
            switch (choice) {
            case 1:
                Game{ T };
                break;
            case 2: 
                T.modifierTerrain();
                cout << "1. Organiser une partie de jeu avec le nouveau terrain modifie\n";
                cout << "0. Sauvegarder le terrain et quitter\n";
                cin >> choice;

                switch (choice)
                {
                       case 1:
                       T.litTerrain(filename);
                       Game{ T };
                              break;
                        case 0:
                        std::cout << "Au revoir !" << std::endl;
                        break;
                }
                
                break;
            case 0:
                std::cout << "Au revoir !" << std::endl;
                break;
            }
        break;
        case 0:
                std::cout << "Au revoir !" << std::endl;
                break;
        default:
                std::cout << "Choix invalide. Réessayez." << std::endl;
                break;
        }

        } while (choice != 0);

        return 0;

}
