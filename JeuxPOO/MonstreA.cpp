#include "MonstreA.h"


MonstreA::MonstreA(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete) :Monstre{ position,pointDeVie, pointDeForce, pourcentageHabilete }
{}

void MonstreA::deplaceAveugle(Terrain& T)
{
	int x = (std::rand() % 3) - 1;
	int y = (std::rand() % 3) - 1;

	deplacer(x, y);
}
