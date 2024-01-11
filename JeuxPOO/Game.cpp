#include "game.h"


Game::Game(const Position& posAventurier)
	{

		Terrain Ter{ 1000,1000 };
		Aventurier a(Position{1,1},100,100,100,100,100);
		Ter.ajoutPersonnage(move(a));
}


