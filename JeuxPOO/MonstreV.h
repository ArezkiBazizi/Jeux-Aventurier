#pragma once
#include "Monstre.h"
#include "Aventurier.h"
#include "Cases.h"

class MonstreV : public Monstre
{
	MonstreV();
	void trouverAventurier(Aventurier& A) override;
	void deplacerVersAventurier(dx, dy);

};

