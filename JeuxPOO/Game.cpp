#include "game.h"


class Game{

	Game::Game(const Position& posAventurier)
	{

		Terrain Ter{ 1000,1000 };
		make_unique<Aventurier>(a{Position{1,1} });
		Ter.AjoutPersonnage(a);
	}


	Terrain Ter{ 1000,1000 };
	Aventurier a{ Position{1,1} };
	MonstreV m{ Position{1,1} };
	Ter.AjoutePersonnage();

}