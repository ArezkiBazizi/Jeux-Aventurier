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

void Monstre::afficheInfoMonstre()
{
    cout << endl;
    cout << "information Monstre" << endl;
    cout << " Point de vie : " << pointDeVie() << endl;
    cout << " Ponit de force : " << pointDeForce() << endl;
}

void Monstre::attaquer(Aventurier& A) const
{
    int probabilite = (static_cast<double>(rand()) / RAND_MAX)*100 ;
    double attaque{ pointDeForce() * 0.9 };

    if (probabilite <= d_pourcentageHabilete){
        if (A.tabEquipement()[0]->typeEquipement() == "Armure") {
            int x = A.tabEquipement()[0]->pointDeSolidite();
            if (x > static_cast<int>((attaque*3 / 4)/2))
            {
                A.tabEquipement()[0]->ModifierpointDeSolidite(static_cast<int>(attaque* 3 / 4));
                A.encaisser(static_cast<int>(attaque*1 / 4));
            }
            else
            { 
                A.tabEquipement()[0]->setPointDeSolidite(0);
                A.encaisser(static_cast<int>(attaque-x));
            }
        }
    }
    else
        return;
   
}


MonstreV::MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) : Monstre{ position,pointDeVie,pointDeForce,pourcentageHabilete }
{
}

string MonstreV::type() const
{
    return "MonstreV";
}

void MonstreV::trouverAventurier(Aventurier& A, Terrain& T)
{
    // Calcul des différences entre les coordonnées du monstre et de l'aventurier
    int dx = A.position().x() - position().x();
    int dy = A.position().y() - position().y();

    if (abs(dx) == 1 && abs(dy) == 1)
    {
        attaquer(A);
    }

    else if (abs(dx) <= 8 && abs(dy) <= 8)
    {
        deplacerVersAventurier(dx, dy, T);
    }
    else
    {
        int x = (std::rand() % 3) - 1;
        int y = (std::rand() % 2);

        if (y == 1)
        {
            switchCases(T.retourneC(position().x() + x, position().y()));
        }
        else
        {
            switchCases(T.retourneC(position().x(), position().y()+x));
        }

    }

}

void MonstreV::deplacerVersAventurier(int dx, int dy, Terrain& T) {

    bool up = T.retourneC(position().x(), position().y() + 1).type()== "Vide";
    bool down = T.retourneC(position().x(), position().y() - 1).type() == "Vide" ;
    bool right = T.retourneC(position().x() + 1, position().y()).type() == "Vide";
    bool left = T.retourneC(position().x() - 1, position().y()).type() == "Vide" ;

    double D = sqrt(pow((dx + 1), 2) + pow(dy, 2));        //droite
    double G = sqrt(pow((dx + -1), 2) + pow(dy, 2));      //gauche
    double H = sqrt(pow((dx), 2) + pow((dy + 1), 2));      //haut
    double B = sqrt(pow((dx + -1), 2) + pow((dy - 1), 2)); //bas
   
    
    std::vector<double> move{ D, G, H, B };

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
                right = false;
            }
            else i++;
        }

        else if (move[i] == G)
        {
            if (left)
            {
                switchCases(T.retourneC(position().x() - 1, position().y()));
                i = 4;
                left = false;
            }
            else i++;
        }
        else if (move[i] == H)
        {
            if (T.retourneC(position().x(), position().y() - 1).type() == "Vide")
            {
                switchCases(T.retourneC(position().x(), position().y() - 1));
                i = 4;
                up = false;
            }
            else i++;
        }
        else if (move[i] == B)
        {
            if (down)
            {
                switchCases(T.retourneC(position().x(), position().y() + 1));
                i = 4;
                down = false;
            }
            else i++;
        }
    }
}


MonstreA::MonstreA(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) :Monstre{ position,pointDeVie, pointDeForce, pourcentageHabilete }
{}

void MonstreA::deplaceAveugle(Terrain& T)
{
    int x = (std::rand() % 3) - 1;
    int y = (std::rand() % 3) - 1;

    deplacer(x, y);
}

string MonstreA::type() const
{
    return "MonstreA";
}