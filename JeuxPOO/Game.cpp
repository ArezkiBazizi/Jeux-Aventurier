#include "game.h"


Game::Game(const Position& posAventurier)
{
	Terrain Ter{ 1000,1000 };
	//unique_ptr<Aventurier> a = make_unique<Aventurier>( posAventurier );

	Aventurier* a = Ter.trouverAventurier();
	Ter.litTerrain();
		cout << a->position().x() << a->position().y() << endl;
	if(a)
	{
		a->deplacerA(Ter);
		cout << a->position().x() << a->position().y() << endl;
	}

}




