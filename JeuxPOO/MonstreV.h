#include "Monstre.h"


class MonstreV : public Monstre
{
public:
	MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
	void trouverAventurier(Aventurier& A,Terrain& T) override;
	void deplacerVersAventurier(int dx, int dy, Terrain& T);

};

