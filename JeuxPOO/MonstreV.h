#ifndef MONSTREV_H
#define MONSTREV_H

#include "Monstre.h"

#include <algorithm>

class Terrain;
class Aventurier;	

class MonstreV : public Monstre
{
public:
	MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
	void trouverAventurier(Aventurier& A,Terrain& T) ;
	void deplacerVersAventurier(int dx, int dy, Terrain& T);

};

#endif // MONSTREV_H