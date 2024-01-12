#include "Aventurier.h"
#include <cmath>
#include <conio.h>
#include<windows.h> 


using namespace std;

Aventurier::Aventurier(const Position& position) :
    
    Personnage{position,100,100}, d_bourseDePieces{0}, d_tabEquipement{}
{
    d_tabEquipement.push_back(make_unique<Armure>(100));
    d_tabEquipement.push_back(make_unique<Epee>(100));
}

string Aventurier::type() const
{
    return "Aventurier";
}

void Aventurier::afficheInfoAventurier()
{
    cout << endl;
    cout << "information Aventurier" << endl;
    cout << " Point de vie : " << pointDeVie() << endl;
    cout << " Ponit de force : " << pointDeForce() << endl;
    cout << " bourse : " << bourseDePieces() << endl;


}

Aventurier::Aventurier(const Position& position, int pointDeVie, int pointDeForce, int bourseDePieces, int PointDeSoliditeArmure, int PointDeSoliditeEpee) :
    Personnage{position,pointDeVie,pointDeForce }, d_bourseDePieces{ bourseDePieces }, d_tabEquipement{}
{
    d_tabEquipement.push_back(std::make_unique<Armure>(PointDeSoliditeArmure));
    d_tabEquipement.push_back(std::make_unique<Epee>(PointDeSoliditeEpee));
}


Aventurier::~Aventurier()
{
    //dtor
}

int Aventurier::bourseDePieces() const {
    return d_bourseDePieces;
}

const std::vector<std::unique_ptr<Equipement>>&  Aventurier::tabEquipement() const
{
    return d_tabEquipement;
}


void Aventurier::deplacerA( Terrain& T) {
    // Tableau pour stocker l'état des touches de direction
    vector<bool> touchesDirection(4,false);

        bool flag = true;
        vector<MonstreV*> m = T.trouverMonstreV();

        while (flag) {
            
            
            if (GetKeyState(VK_UP) & 0x8000) {
                if (T.retourneC(position().x(), position().y() - 1).type() == "Vide") {

                    cout << "up";

                    switchCases(T.retourneC(position().x(), position().y() - 1));

                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "MonstreV")
                {
                    
                    for (int i = 0; i < m.size(); i++)
                    {
                        if (m[i]->position().x() == position().x() || m[i]->position().y() == position().y()-1)
                        {
                            Attaquer(*m[i]);
                        }
                    }
                   
                }

                flag = false;
               
                
            }
            else if (GetKeyState(VK_DOWN) & 0x8000) {
                if (T.retourneC(position().x(), position().y() + 1).type() == "Vide") {


                    switchCases(T.retourneC(position().x(), position().y() + 1));
                    

                }
                else if (T.retourneC(position().x(), position().y() + 1).type() == "MonstreV")
                {

                    for (int i = 0; i < m.size(); i++)
                    {
                        if (m[i]->position().x() == position().x() || m[i]->position().y() == position().y() + 1)
                        {
                            Attaquer(*m[i]);
                        }
                    }

                }
                flag = 0;
               
               
            }
            else if (GetKeyState(VK_LEFT) & 0x8000) {
                if (T.retourneC(position().x() - 1, position().y()).type() == "Vide") {


                    switchCases(T.retourneC(position().x() - 1, position().y()));
                   
                    

                }
                else if (T.retourneC(position().x()-1, position().y()).type() == "MonstreV")
                {

                    for (int i = 0; i < m.size(); i++)
                    {
                        if (m[i]->position().x() == position().x()-1 || m[i]->position().y() == position().y() )
                        {
                            Attaquer(*m[i]);
                        }
                    }

                }
                flag = 0;
               
                
            }
            else if (GetKeyState(VK_RIGHT) & 0x8000) {
                if (T.retourneC(position().x() + 1, position().y()).type() == "Vide") {

                    switchCases(T.retourneC(position().x() + 1, position().y()));
                    
                }
                else if (T.retourneC(position().x()+1, position().y()).type() == "MonstreV")
                {

                    for (int i = 0; i < m.size(); i++)
                    {
                        if (m[i]->position().x() == position().x()+1 || m[i]->position().y() == position().y())
                        {
                            Attaquer(*m[i]);
                        }
                    }

                }
                flag = 0;
               
               
                
            }
            Sleep(100);
            
        }



        // Appliquer la logique de déplacement en fonction de l'état des touches
        if (touchesDirection[0])
        {


            if (T.retourneC(position().x(), position().y() - 1).type() == "Vide") {



                switchCases(T.retourneC(position().x(), position().y() - 1));
                
                touchesDirection[0] = false;

            }
        }
        if (touchesDirection[1])
        {
        if (T.retourneC(position().x(), position().y() - 1).type() == "Vide") {
            
          
                deplacer(0, -1);  // Down
                


            }
        }
        if (touchesDirection[2] )
        {
            if (T.retourneC(position().x() - 1, position().y()).type() == "Vide") {
            
    
                deplacer(-1, 0); // Left
                


            }
        }
        if (touchesDirection[3] )
        {
            if (T.retourneC(position().x() + 1, position().y()).type() == "Vide") {

                deplacer(1, 0);  // Right
               

            }
        }

      
        
        system("cls");
        //T.ecritTerrain();
        //T.litTerrain();
        T.afficheTerrain();


    //cout << b.type() << endl;
}

void Aventurier::Attaquer(Monstre& M) {
    
    int degat{ static_cast<int>((pointDeForce() + d_tabEquipement[1]->pointDeSolidite()) * 0.9) };
    double probabilite = (static_cast<double>(rand()) / RAND_MAX);

    if (probabilite <= 0.8) {
        if (((M.position().x() - position().x()) == 1) && ((M.position().y() - position().y()) == 1)) 
        {
            M.encaisser(degat);
            if (M.pointDeVie() < 0)
                M.modifierPointDeVie(0);
        }

        if (d_tabEquipement[1]->pointDeSolidite() > 0) {
            d_tabEquipement[1]->setPointDeSolidite(d_tabEquipement[1]->pointDeSolidite() - 1);
        }

        if (!M.estVivant()) {
            modifierPointDeForce(pointDeForce() + static_cast<int>(0.25 * M.pointDeForce()));
            modifierPointDeVie(pointDeVie() + static_cast<int>(0.75 * M.pointDeForce()));
        }
    }
    else
        return;
}

bool Aventurier::ramasserAllumette(Amullette& A, Terrain& T) {
    if ((A.position().x() == position().x()) && (A.position().y() == position().y())) {
        switchCases(A);
        T.remplaceCase(A);
        return true;
    }
}


void Aventurier::ramasserPieces(Pieces& P, Terrain& T) {
    if ((P.position().x() == position().x() ) && (P.position().y() == position().y() )) {
        d_bourseDePieces += P.valeur(); 
        switchCases(P);
        T.remplaceCase(P);
      
    }
    

}

bool Aventurier::estSortie(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y())->type() == "sortie");
}