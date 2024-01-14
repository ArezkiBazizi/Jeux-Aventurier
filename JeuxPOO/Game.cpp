#include "game.h"


Game::Game(const Position& posAventurier)
{

	Terrain Ter{ 1000,1000 };
	Ter.litTerrain();

	Aventurier* a = Ter.trouverAventurier();
	vector<MonstreV*> m = Ter.trouverMonstreV();

	Ter.afficheTerrain();
	while (a->estVivant()) {
		
		for (int i = 0; i < m.size(); i++)
		{
			m[i]->trouverAventurier(*a, Ter);
		}
		a->deplacerA(Ter);
		a->afficheInfoAventurier();
		
	}
		
}
			




