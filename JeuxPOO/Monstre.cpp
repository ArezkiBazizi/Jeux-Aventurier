#include "Monstre.h"
#include <algorithm>

Monstre::Monstre(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) :
    Personnage{ position,pointDeVie,pointDeForce }, d_pourcentageHabilete{ pourcentageHabilete }
{

}


Monstre::~Monstre()
{
    //dtor
}


int Monstre::obtenirPourcentageHabilete() const
{
    return d_pourcentageHabilete;
}

void Monstre::afficheInfoMonstre(int i)
{
    if (estVivant())
    {   
        std::cout << "\x1b[" << i*5+1 << ";50H";
        cout << "************************" << endl;
        std::cout << "\x1b[" << i*5+2 << ";50H";
        cout << "* information Monstre  *" << endl;
        std::cout << "\x1b[" << i * 5+3 << ";50H";
        cout << "* Point de vie : " << pointDeVie() <<"   *" << endl;
        std::cout << "\x1b[" << i * 5+4 << ";50H";
        cout << "* Ponit de force : " << pointDeForce() <<" *" << endl;
        std::cout << "\x1b[" << i * 5+5 << ";50H";
        cout << "************************" << endl;
    }
}

void Monstre::attaquer(Terrain& T)
{

    Aventurier* A = T.trouverAventurier();

    double probabilite = (static_cast<double>(rand()) / RAND_MAX) * 100;
    double attaque{ static_cast<double>(pointDeForce()) * 0.9 };

    if (probabilite <= d_pourcentageHabilete) {
        if (A->tabEquipement()[0]->typeEquipement() == "Armure") {

            cout << "ATTAAAAAQUE";
            int x = A->tabEquipement()[0]->pointDeSolidite();
            if (x > static_cast<int>((attaque * 3 / 4) / 2))
            {

                A->tabEquipement()[0]->ModifierpointDeSolidite(static_cast<int>(attaque * 3 / 4));
                A->encaisser(static_cast<int>(attaque * 1 / 4));
            }
            else
            {
                A->tabEquipement()[0]->setPointDeSolidite(0);
                A->encaisser(static_cast<int>(attaque - x));
            }
        }
        else
            return;


    }
}

MonstreV::MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) : Monstre{ position,pointDeVie,pointDeForce,pourcentageHabilete }
{
}

string MonstreV::type() const
{
    return "MonstreV";
}

void MonstreV::trouverAventurier(Terrain& T)
{

    Aventurier* A = T.trouverAventurier();


    if (!estVivant()){
        T.remplaceCase(*this);
    }

    else {
        // Calcul des différences entre les coordonnées du monstre et de l'aventurier
        int dx = A->position().x() - position().x();
        int dy = A->position().y() - position().y();

        if (abs(dx) <= 8 && abs(dy) <= 8)
        {


            if (abs(dx) <= 1 && abs(dy) <= 1)
            {
                attaquer(T);
            }
            else {
                deplacerVersAventurier(dx, dy, T);
            }

        }
        else
        {
            int x = (std::rand() % 3) - 1;
            int y = (std::rand() % 2);

            if (y == 0) {

                while ((T.retourneC(position().x() + x, position().y()).type() != "Vide"))
                {
                    x = (std::rand() % 2) * 2 - 1;
                };
                switchCases(T.retourneC(position().x() + x, position().y()));
            }
            else{
                while ((T.retourneC(position().x(), position().y() + x).type() != "Vide"))
                {
                    x = (std::rand() % 2) * 2 - 1;
                };
                switchCases(T.retourneC(position().x(), position().y() + x));
            }

          

        }
    }

}

void MonstreV::deplacerVersAventurier(int dx, int dy, Terrain& T) {

    double D, G, B, H;

    if (dx >= 0)
    {
        D = sqrt(pow(dx - 1, 2) + pow(abs(dy), 2));        //droite
        G = sqrt(pow(dx + 1, 2) + pow(abs(dy), 2));
    }
    else
    { 
         D = sqrt(pow(abs(dx) + 1, 2) + pow(abs(dy), 2));        //droite
         G = sqrt(pow(abs(dx) - 1, 2) + pow(abs(dy), 2));
    }


    if (dy >= 0)
    {
         H = sqrt(pow(abs(dx), 2) + pow(dy+ 1, 2));
         B = sqrt(pow(abs(dx), 2) + pow(dy - 1, 2));

    }
    else
    {
         H = sqrt(pow(abs(dx), 2) + pow(abs(dy) - 1, 2));
         B = sqrt(pow(abs(dx), 2) + pow(abs(dy) + 1, 2));

    }
    
    std::vector<double> move{ G, D, H, B };

    std::sort(move.begin(), move.end());

    int i = 0;
    while (i < 4)
    {
      
        if (move[i] == D)
        {
            if (T.retourneC(position().x() + 1, position().y()).type() == "Vide")
            {
                switchCases(T.retourneC(position().x() + 1, position().y()));
                i = 4;
                
            }
            else i++;
        }

        else if (move[i] == G)
        {
            if (T.retourneC(position().x()-1, position().y()).type() == "Vide")
            {
                switchCases(T.retourneC(position().x() - 1, position().y()));
                i = 4;
               
            }
            else i++;
        }
        else if (move[i] == H)
        {
            if (T.retourneC(position().x(), position().y() - 1).type() == "Vide")
            {
                switchCases(T.retourneC(position().x(), position().y() - 1));
                i = 4;
               
            }
            else i++;
        }
        else if (move[i] == B)
        {
            if (T.retourneC(position().x(), position().y() + 1).type() == "Vide")
            {
                switchCases(T.retourneC(position().x(), position().y() + 1));
                i = 4;
               
            }
            else i++;
        }
    }
}


MonstreA::MonstreA(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) :Monstre{ position,pointDeVie, pointDeForce, pourcentageHabilete }
{}

void MonstreA::deplaceAveugle(Terrain& T)
{
    if (!estVivant()) {
        T.remplaceCase(*this);
    }
    else {

        Aventurier* A = T.trouverAventurier();

        int dx = A->position().x() - position().x();
        int dy = A->position().y() - position().y();



        if (abs(dx) <= 3 && abs(dy) <= 3)
        {
            afficheInfoMonstre(5);
        }

        if (abs(dx) <= 1 && abs(dy) <= 1)
        {
            attaquer(T);
        }
        else {


            int x = (std::rand() % 2) * 2 - 1;
            int z = (std::rand() % 2) * 2 - 1;
            int y = (std::rand() % 3);


            if (y == 0) {

                while ((T.retourneC(position().x() + x, position().y()).type() != "Vide"))
                {
                    x = (std::rand() % 2) * 2 - 1;
                };
                switchCases(T.retourneC(position().x() + x, position().y()));
            }
            else if (y == 1) {
                while ((T.retourneC(position().x(), position().y() + x).type() != "Vide"))
                {
                    x = (std::rand() % 2) * 2 - 1;
                };
                switchCases(T.retourneC(position().x(), position().y() + x));
            }
            else {
                while ((T.retourneC(position().x() + z, position().y() + x).type() != "Vide"))
                {
                    x = (std::rand() % 2) * 2 - 1;
                    z = (std::rand() % 2) * 2 - 1;
                };
                switchCases(T.retourneC(position().x() + z, position().y() + x));
            }
        }
    }
}

string MonstreA::type() const
{
    return "MonstreA";
}


bool Monstre::distance(const Personnage& perso, int dist) const {
    return abs(perso.position().x() - position().x()) <= dist && abs(perso.position().y() - position().y()) <= dist;
}