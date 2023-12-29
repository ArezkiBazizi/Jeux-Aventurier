
#include "Monstre.h"
#include "Aventurier.h"


class MonstreV : public Monstre
{
	MonstreV();
	void trouverAventurier(Aventurier& A,Terrain& T) override;
	void deplacerVersAventurier(int dx, int dy, Terrain& T);

};

