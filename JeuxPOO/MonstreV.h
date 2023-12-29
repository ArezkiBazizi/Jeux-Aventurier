
#include "Monstre.h"
#include "Aventurier.h"
#include "Terrain.h"

class MonstreV : public Monstre
{
	MonstreV();
	void trouverAventurier(Aventurier& A) override;
	void deplacerVersAventurier(int dx, int dy);

};

