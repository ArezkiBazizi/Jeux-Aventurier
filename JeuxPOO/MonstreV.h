#pragma once
#include "Monstre.h"
#include "Aventurier.h"

class MonstreV : public Monstre
{
	MonstreV();
	void trouverAventurier(Aventurier& A) override;

};

