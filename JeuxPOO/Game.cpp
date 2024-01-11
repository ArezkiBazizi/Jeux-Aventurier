#include "game.h"


Game::Game(const Position& posAventurier)
	{

		Terrain Ter{ 1000,1000 };
		Aventurier a{ posAventurier };
		//unique_ptr<Aventurier> a  = make_unique<Aventurier>( posAventurier );
		
	
		Ter.litTerrain();
		
		Ter.ajoutPersonnage(move(a));
		//Ter.afficheTerrain();
		//Ter.retourne();
		cout << a->position().x() << " " << a->position().y() << endl;
		a->deplacerA(Ter);
		cout << a->position().x() << " " << a->position().y();
		//Ter.afficheTerrain();
		cout << "/////////";
		//Ter.ecritTerrain();
		goto_xy(10, 10);
		//Ter.retourne();
}


