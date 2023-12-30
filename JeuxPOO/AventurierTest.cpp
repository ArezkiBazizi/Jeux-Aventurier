#include "doctest.h"
#include "Epee.h"
#include "Aventurier.h"

TEST_CASE("[Aventurier] Aventurier : construire l'aventurier") 
{

	SUBCASE("Le constructeur avec la position, point de vie, point de force et bourses de pieces fonctionne")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		int v{ 100 };
		int f{ 100 };
		int b{ 0 };

		Aventurier a{p,v,f,b };
		
		vector<unique_ptr<Equipement>> tab;
		tab.push_back(std::make_unique<Armure>(100));
		tab.push_back(std::make_unique<Epee>(100));

		REQUIRE(a.bourseDePieces() == b);

	}
	SUBCASE("Le constructeur avec juste la position fonctionne")
	{
		//constructeur
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{p};
		REQUIRE(a.bourseDePieces() == 0);

	}
}

TEST_CASE("[Aventurier] Aventurier : ajouter un equipement ") 
{
	SUBCASE("L'equipement est contruit et ajouter correctement")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.ajouterEquipement("Epee", 10);
		Epee e{ 10 };
		REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 10);


	}

}
