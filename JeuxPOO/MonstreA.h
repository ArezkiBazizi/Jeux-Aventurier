#pragma once
#include "Monstre.h"
class MonstreA : public Monstre
{
public: 
	MonstreA(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
	void deplaceAveugle(Terrain& T);
};

