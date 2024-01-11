/*#include "doctest.h"
#include "Aventurier.h"
#include "Monstre.h"

TEST_CASE("[Monstre] Monstre : construire le monstre")
{

	SUBCASE("Le constructeur avec la position, point de vie, point de force et pourcentage d'habilité")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		int v{ 100 };
		int f{ 100 };
		int b{ 30 };


		Monstre a{ p,v,f,b };


		REQUIRE(a.position().x() == x);
		REQUIRE(a.position().y() == y);			 
		REQUIRE(a.pointDeVie() == v);		 
		REQUIRE(a.pointDeForce() == f);		
		REQUIRE(a.obtenirPourcentageHabilete() == b);	 

	}
}

TEST_CASE("attaquer l'aventurier") {

	SUBCASE("L'armure de l'aventurier encaisse l'attaque")
	{
		SUBCASE("les points de solidite de l'armure est superieur par rapport à l'attaque ")
		{
			Aventurier a{ Position{2,1},100,30,100, 100, 20 };
			Monstre m{ Position{1,1},100,100,40 };
			m.attaquer(a);
			REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 67);
		}
		SUBCASE("les points de solidite de l'armure est inferieur par rapport à l'attaque")
		{
			Aventurier a{ Position{2,1},100,30,100, 10, 20 };
			Monstre m{ Position{1,1},100,100,40 };
			m.attaquer(a);
			REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 10);
		}
		
	}

	SUBCASE(" l'aventurier encaisse l'attaque") {
		SUBCASE("les points de solidite de l'armure sont superieur par rapport à l'attaque ")
		{
			Aventurier a{ Position{2,1},100,30,100, 100, 20 };
			Monstre m{ Position{1,1},100,100,40 };
			m.attaquer(a);
			REQUIRE(a.pointDeVie() == 78);
		}
		SUBCASE("les points de solidite de l'armure sont inferieur par rapport à l'attaque")
		{
			Aventurier a{ Position{2,1},100,30,100, 10, 20 };
			Monstre m{ Position{1,1},100,100,40 };
			m.attaquer(a);
			REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 10);
		}
	}
}*/