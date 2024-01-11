#include "game.h"


Game::Game(const Position& posAventurier)
{

		Terrain Ter{1000,1000};
		//unique_ptr<Aventurier> a = make_unique<Aventurier>( posAventurier );
		Ter.litTerrain();
		
		Ter.ajoutPersonnage(move(a));
		Ter.afficheTerrain();
		//Ter.retourne();
		a->deplacerA(Ter);
		Ter.afficheTerrain();
		cout << "/////////";
		Ter.ecritTerrain();
		goto_xy(10, 10);
		Ter.retourne();
}




