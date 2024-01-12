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

        while (flag) {
            
            
            if (GetKeyState(VK_UP) & 0x8000) {
                if (T.retourneC(position().x(), position().y() - 1).type() == "Vide") {

                    cout << "up";

                    switchCases(T.retourneC(position().x(), position().y() - 1));

                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "MonstreV")
                {
                    
                    combat(T.retourneC(position().x() , position().y()-1), T);
                   
                }

                flag = false;
               
                
            }
            else if (GetKeyState(VK_DOWN) & 0x8000) {
                if (T.retourneC(position().x(), position().y() + 1).type() == "Vide") {


                    switchCases(T.retourneC(position().x(), position().y() + 1));
                    

                }
                else if (T.retourneC(position().x(), position().y() + 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x(), position().y()+1), T);

                }
                flag = 0;
               
               
            }
            else if (GetKeyState(VK_LEFT) & 0x8000) {
                if (T.retourneC(position().x() - 1, position().y()).type() == "Vide") {


                    switchCases(T.retourneC(position().x() - 1, position().y()));
                   
                    

                }
                else if (T.retourneC(position().x()-1, position().y()).type() == "MonstreV")
                {


                    combat(T.retourneC(position().x() - 1, position().y()), T);

                }
                flag = 0;
               
                
            }
            else if (GetKeyState(VK_RIGHT) & 0x8000) {
                if (T.retourneC(position().x() + 1, position().y()).type() == "Vide") {

                    switchCases(T.retourneC(position().x() + 1, position().y()));
                    
                }
                else if (T.retourneC(position().x()+1, position().y()).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() + 1, position().y()),T);

                }
                flag = 0;
               
               
                
            }
            Sleep(100);
            
        }

      
        
        system("cls");
        //T.ecritTerrain();
        //T.litTerrain();
        T.afficheTerrain();


    //cout << b.type() << endl;
}


void Aventurier::combat(Cases& c, Terrain& T)
{
    vector<MonstreV*> m = T.trouverMonstreV();
    for (int i = 0; i < m.size(); i++)
    {
        Attaquer(*m[i]);
    }
    
}



void Aventurier::Attaquer(Monstre& M) {
    
    int degat{ static_cast<int>((pointDeForce() + d_tabEquipement[1]->pointDeSolidite()) * 0.9) };
    double probabilite = (static_cast<double>(rand()) / RAND_MAX);


    if (probabilite <= 0.8) {
        cout << abs(M.position().x() - position().x()) << abs(M.position().y() - position().y()) <<endl;
        if ((abs(M.position().x() - position().x()) == 1) && (abs(M.position().y() - position().y()) == 1)) 
        {
            cout << degat;
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

bool Aventurier::TrouverAllumette(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y())->type() == "Amullette");
}


void Aventurier::ramasserPieces(Pieces& P, Terrain& T) {
    if ((P.position().x() == position().x() ) && (P.position().y() == position().y() )) {
        d_bourseDePieces += P.valeur(); 
        Vide V{P.position().x(), position().y()};
        switchCases(P);
       // P = V;
        
        
    }
    

}

bool Aventurier::estSortie(Terrain& T) const {
    return (T.retourneCase(position().x(), position().y())->type() == "sortie");
}