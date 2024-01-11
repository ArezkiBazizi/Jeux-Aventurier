#include "game.h"


Game::Game(const Position& posAventurier)
{

		Terrain Ter{1000,1000};
		//unique_ptr<Aventurier> a = make_unique<Aventurier>( posAventurier );
		Ter.litTerrain();
		Aventurier* a = Ter.trouverAventurier();
		Ter.afficheTerrain();
		if (a) {
			cout << a->position().x() << a->position().y() << endl;
			a->deplacerA(Ter);
			cout << a->position().x() << a->position().y() << endl;
		}

}




