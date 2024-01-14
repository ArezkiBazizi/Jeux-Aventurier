#pragma once
#include <iostream>
#include <cstdlib>  // Pour la fonction rand()
#include <ctime>    // Pour initialiser la graine de la fonction rand()
#include <cmath>
#include "Personnage.h"
#include "Aventurier.h"

class Aventurier;
class Terrain;

class Monstre : public Personnage
{
    public:
        Monstre(const Position& position, int pointDeVie,int pointDeForce, int pourcentageHabilete);
        void attaquer(Terrain& T);
        int obtenirPourcentageHabilete() const;
        virtual void afficheInfoMonstre(int i) const =0;
        virtual ~Monstre();
    protected:

    private:
        int d_pourcentageHabilete;
};

class MonstreV : public Monstre
{
public:
    MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
    void trouverAventurier(Terrain& T);
    void deplacerVersAventurier(int dx, int dy, Terrain& T);
    void afficheInfoMonstre(int i) const override;
    string type() const override;
    
};

class MonstreA : public Monstre
{
public:
    MonstreA(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
    void deplaceAveugle(Terrain& T);
    string type() const override;
    void afficheInfoMonstre(int i) const override;
};




