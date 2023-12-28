#ifndef MONSTRE_H
#define MONSTRE_H
#include <iostream>
#include <cstdlib>  // Pour la fonction rand()
#include <ctime>    // Pour initialiser la graine de la fonction rand()
#include <cmath>
#include "Personnage.h"
#include "Aventurier.h"

class Monstre : public Personnage
{
    public:
        Monstre(const Position& position, int pointDeVie,int pointDeForce, int pourcentageHabilete);
        void attaquer(Aventurier& A) const;
        int obtenirPourcentageHabilete() const;
        virtual void trouverAventurier(Aventurier& A);
        virtual ~Monstre();

    protected:

    private:
        int d_pourcentageHabilete;
};

#endif // MONSTRE_H
