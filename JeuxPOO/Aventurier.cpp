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
    cout << endl;
    cout << "**************************" << endl;
    cout << "* Information Aventurier *" << endl;
    cout << "* Point de vie : " << pointDeVie()<<"     *" << endl;
    cout << "* Point de force : " << pointDeForce() << "   *" << endl;
    cout << "* Solidite epee : " << tabEquipement()[1]->pointDeSolidite() << "    *" << endl;
    cout << "* Solidite armure : " << tabEquipement()[0]->pointDeSolidite() << "  *" << endl;
    cout << "* Bourse : " << bourseDePieces() << "             *" << endl;
    cout << "**************************" << endl;


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
            
            
            if (GetKeyState('W') & 0x8000) {
                if (T.retourneC(position().x(), position().y() - 1).type() == "Vide"){


                    switchCases(T.retourneC(position().x(), position().y() - 1));

                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "MonstreV")
                {
                    
                    combat(T.retourneC(position().x() , position().y() -1 ), T);
                   
                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x(), position().y() - 1), T);

                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x(), position().y() - 1));
                }
                else if (T.retourneC(position().x(), position().y() - 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x(), position().y() - 1));

                }
                else if (T.retourneC(position().x(), position().y()-1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() , position().y()-1));

                }



                flag = false;
               
                
            }
            else if (GetKeyState('S') & 0x8000) {
                if (T.retourneC(position().x(), position().y() + 1).type() == "Vide") {


                    switchCases(T.retourneC(position().x(), position().y() + 1));
                    

                }
                else if (T.retourneC(position().x(), position().y() + 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x(), position().y() + 1), T);

                }
                else if (T.retourneC(position().x(), position().y() + 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x(), position().y() + 1), T);

                }
                else if (T.retourneC(position().x(), position().y()+1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x(), position().y() + 1));
                }
                else if (T.retourneC(position().x(), position().y() + 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x(), position().y() + 1));

                }
                else if (T.retourneC(position().x(), position().y()+1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x(), position().y()+1));

                }


                flag = 0;
               
               
            }
            else if (GetKeyState('A') & 0x8000) {
                if (T.retourneC(position().x() - 1, position().y()).type() == "Vide") {


                    switchCases(T.retourneC(position().x() - 1, position().y()));
                   
                    

                }
                else if (T.retourneC(position().x()-1, position().y()).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() - 1, position().y()), T);

                }
                else if (T.retourneC(position().x() - 1, position().y()).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() - 1, position().y()), T);

                }
                else if (T.retourneC(position().x() - 1, position().y()).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x()-1, position().y()));
                }
                else if (T.retourneC(position().x()-1, position().y()).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x() - 1, position().y()));
                }
                else if (T.retourneC(position().x() - 1, position().y()).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() - 1, position().y()));

                }

                flag = 0;
               
                
            }
            else if (GetKeyState('D') & 0x8000) {
                if (T.retourneC(position().x() + 1, position().y()).type() == "Vide") {

                    switchCases(T.retourneC(position().x() + 1, position().y()));
                    
                }
                else if (T.retourneC(position().x()+1, position().y()).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() +1, position().y()), T);

                }
                else if (T.retourneC(position().x() + 1, position().y()).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() + 1, position().y()), T);

                }
                else if (T.retourneC(position().x() + 1, position().y()).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x()+1, position().y()));
                }
                else if (T.retourneC(position().x()+1, position().y()).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x()+1, position().y() ));

                }
                else if (T.retourneC(position().x() + 1, position().y()).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() + 1, position().y()));

                }

                flag = 0;
               
               
                
            }
            else if (GetKeyState('Q') & 0x8000) {
                if (T.retourneC(position().x() - 1, position().y() -1).type() == "Vide") {

                    switchCases(T.retourneC(position().x() - 1, position().y() - 1));

                }
                else if (T.retourneC(position().x() - 1, position().y() - 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() - 1, position().y() - 1), T);

                }
                else if (T.retourneC(position().x() - 1, position().y() - 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() - 1, position().y() - 1), T);

                }
                else if (T.retourneC(position().x() - 1, position().y() - 1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x() - 1, position().y() - 1));
                }
                else if (T.retourneC(position().x() - 1, position().y() - 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x() - 1, position().y() - 1));

                }
                else if (T.retourneC(position().x() - 1, position().y() - 1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() - 1, position().y() - 1));

                }

                flag = 0;



                }
            else if (GetKeyState('E') & 0x8000) {
                if (T.retourneC(position().x() + 1, position().y() - 1).type() == "Vide") {

                    switchCases(T.retourneC(position().x() + 1, position().y() - 1));

                }
                else if (T.retourneC(position().x() + 1, position().y() - 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() + 1, position().y() - 1), T);

                }
                else if (T.retourneC(position().x() + 1, position().y() - 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() + 1, position().y() - 1), T);

                }
                else if (T.retourneC(position().x() + 1, position().y() - 1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x() + 1, position().y() - 1));
                }
                else if (T.retourneC(position().x() + 1, position().y() - 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x() + 1, position().y() - 1));

                }
                else if (T.retourneC(position().x() + 1, position().y() - 1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() + 1, position().y() - 1));

                }

                flag = 0;



                }
            else if (GetKeyState('Z') & 0x8000) {
                if (T.retourneC(position().x() - 1, position().y() + 1).type() == "Vide") {

                    switchCases(T.retourneC(position().x() - 1, position().y() + 1));

                }
                else if (T.retourneC(position().x() - 1, position().y() + 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() - 1, position().y() + 1), T);

                }
                else if (T.retourneC(position().x() - 1, position().y() + 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() - 1, position().y() + 1), T);

                }
                else if (T.retourneC(position().x() - 1, position().y() + 1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x() - 1, position().y() + 1));
                }
                else if (T.retourneC(position().x() - 1, position().y() + 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x() - 1, position().y() + 1));

                }
                else if (T.retourneC(position().x() - 1, position().y() + 1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() - 1, position().y() + 1));

                }

                flag = 0;



                }
            else if (GetKeyState('C') & 0x8000) {
                if (T.retourneC(position().x() + 1, position().y() + 1).type() == "Vide") {

                    switchCases(T.retourneC(position().x() + 1, position().y() + 1));

                }
                else if (T.retourneC(position().x() + 1, position().y() + 1).type() == "MonstreV")
                {

                    combat(T.retourneC(position().x() + 1, position().y() + 1), T);

                }
                else if (T.retourneC(position().x() + 1, position().y() + 1).type() == "MonstreA")
                {

                    combat(T.retourneC(position().x() + 1, position().y() + 1), T);

                }
                else if (T.retourneC(position().x() + 1, position().y() + 1).type() == "Amullette") {

                    ramasserAmullette(T, T.retourneC(position().x() + 1, position().y() + 1));
                }
                else if (T.retourneC(position().x() + 1, position().y() + 1).type() == "Sortie") {

                    sortir(T, T.retourneC(position().x() + 1, position().y() + 1));

                }
                else if (T.retourneC(position().x() + 1, position().y() + 1).type() == "Pieces") {

                    ramasserPieces(T, T.retourneC(position().x() + 1, position().y() + 1));

                }

                flag = 0;



                }
            else if((GetKeyState('X') & 0x8000))
                flag = 0;
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
    vector<MonstreA*> ma = T.trouverMonstreA();
     
    if (c.type() == "MonstreV")
    {
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i]->position().x() == c.position().x() && m[i]->position().y() == c.position().y())
                Attaquer(*m[i]);
        }

    }
    else
    {
        for (int i = 0; i < ma.size(); i++)
        {
            if (ma[i]->position().x() == c.position().x() && ma[i]->position().y() == c.position().y())
                Attaquer(*ma[i]);
        }
    }
}



void Aventurier::Attaquer( Monstre& M) {
    
    int degat{ static_cast<int>((pointDeForce() + d_tabEquipement[1]->pointDeSolidite())*0.9) };
    double probabilite = (static_cast<double>(rand()) / RAND_MAX);

    cout << endl<< "degat : "<< degat;

    if (probabilite <= 0.8) {

        M.encaisser(degat);

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

void Aventurier::ramasserAmullette(Terrain& T,Cases& c) {

    Amullette* A = T.trouverAmullette();

 

    if ((A->position().x() == c.position().x()) && (A->position().y() == c.position().y())) {

      
        switchCases(c);
        T.remplaceCase(c);
        A->changeEtatAllumettes(true);
       
    }
}

void Aventurier::sortir(Terrain& T, Cases& c) {

    Sortie* S = T.trouverSortie();



    if ((S->position().x() == c.position().x()) && (S->position().y() == c.position().y())) {


        switchCases(c);
        T.remplaceCase(c);
        T.remplaceCase(*this);
        d_sortir = true;

    }
}


void Aventurier::ramasserPieces(Terrain& T, Cases& c) {

    vector<Pieces*> p = T.trouverPieces();

    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i]->position().x() == c.position().x()) && (p[i]->position().y() == c.position().y())) {
            d_bourseDePieces += p[i]->valeur();
            switchCases(c);
            T.remplaceCase(c);


        }
    }
    

}

bool Aventurier::estSortie() const 
{
    return d_sortir;
}