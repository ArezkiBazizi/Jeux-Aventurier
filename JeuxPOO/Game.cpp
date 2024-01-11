#include "game.h"


Game::Game(const Position& posAventurier)
	{

		Terrain Ter{ 1000,1000 };
		unique_ptr<Aventurier> a = make_unique<Aventurier>( Position{1,1} );


		Ter.AjoutPersonnage(a);
}


