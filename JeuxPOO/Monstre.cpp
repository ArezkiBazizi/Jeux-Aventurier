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

void Monstre::attaquer(Aventurier& A) const
{
    int i = 0;
    while (i <= A.tabEquipement().size())
    {
    if (A.tabEquipement()[i]->typeEquipement() == "Armure") {
        int x = A.tabEquipement()[i]->pointDeSolidite();
        if (x >= d_pourcentageHabilete*3 / 4)
        {
            A.tabEquipement()[i]->ModifierpointDeSolidite(d_pourcentageHabilete * 3 / 4);
            A.encaisser(d_pourcentageHabilete * 1 / 4);
        }
        else
        { 
            A.tabEquipement()[i]->ModifierpointDeSolidite(x);
            A.encaisser(d_pourcentageHabilete - x + d_pourcentageHabilete/4);
        }
    }
    i++;
   }
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

    if ((dx == 1) && (dy == 1))
    {
        attaquer(A);
    }

    else if (abs(dx) == 8 && abs(dy) == 8)
    {
        deplacerVersAventurier(dx, dy, T);
    }
    else
    {
        int x = (std::rand() % 3) - 1;
        int y = (std::rand() % 2);

        if (y == 0)
        {
            deplacer(x, 0);
        }
        else
        {
            deplacer(0, x);
        }

    }

}

void MonstreV::deplacerVersAventurier(int dx, int dy, Terrain& T) {

    bool up = T.retourneCase(position().x(), position().y() + 1)->type() == "vide";
    bool down = T.retourneCase(position().x(), position().y() - 1)->type() == "vide";
    bool right = T.retourneCase(position().x() + 1, position().y())->type() == "vide";
    bool left = T.retourneCase(position().x() - 1, position().y())->type() == "vide";

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
            if (right)
            {
                deplacer(1, 0);
            }
            else i++;
        }

        if (move[i] == G)
        {
            if (left)
            {
                deplacer(-1, 0);
            }
            else i++;
        }
        if (move[i] == H)
        {
            if (up)
            {
                deplacer(0, 1);
            }
            else i++;
        }
        if (move[i] == B)
        {
            if (down)
            {
                deplacer(0, -1);
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