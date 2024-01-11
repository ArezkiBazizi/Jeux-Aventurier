#include "game.h"


Game::Game(const Position& posAventurier)
{

	Terrain Ter{ 1000,1000 };
	Ter.litTerrain();

	Aventurier* a = Ter.trouverAventurier();

	Ter.afficheTerrain();
	while (a->estVivant()) {
		
		a->deplacerA(Ter);
	}
		
}
			




