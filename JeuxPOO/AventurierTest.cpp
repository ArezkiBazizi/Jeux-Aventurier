/*
#include "doctest.h"
#include "Epee.h"
#include "Aventurier.h"
#include "Monstre.h"

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

		
		REQUIRE(a.position().x() == x);			 //position x
		REQUIRE(a.position().y() == y);			 //position y
		REQUIRE(a.pointDeVie() == v);		 //point de vie
		REQUIRE(a.pointDeForce() == f);		 //point de force
		REQUIRE(a.bourseDePieces() == b);	 //bourse de pieces


	}
	SUBCASE("Le constructeur avec juste la position fonctionne")
	{
		//constructeur
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{p};
		REQUIRE(a.bourseDePieces() == 0);

		REQUIRE(a.position().x() == x);			 //position x
		REQUIRE(a.position().y() == y);			 //position y
		REQUIRE(a.pointDeVie() == 100);		 //point de vie
		REQUIRE(a.pointDeForce() == 100);		 //point de force
		REQUIRE(a.bourseDePieces() == 0);	 //bourse de pieces

	}
}


TEST_CASE("[Aventurier] Aventurier : modifier l'aventurier ")
{
	SUBCASE("modifier les points de vie")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.modifierPointDeVie(20);
		REQUIRE(a.pointDeVie() == 20);


	}

	SUBCASE("modifier les points de force")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.modifierPointDeForce(20);
		REQUIRE(a.pointDeForce() == 20);


	}
	SUBCASE("modifier la position")
	{
		int x{ 3 };
		int y{ 3 };
		Position p{ x,y };
		Aventurier a{ p };
		a.deplacer(1,2);
		REQUIRE(a.position().x() == 4);
		REQUIRE(a.position().y() == 5);


	}

}


TEST_CASE("[Aventurier] Aventurier : Encaisser ")
{
	SUBCASE("Encaisser à l'aventurier un coup d'un monstre")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.encaisser(20);
		REQUIRE(a.pointDeVie() == 100-20);

	}


}




TEST_CASE("[Aventurier] Aventurier : ajouter un equipement ") 
{
	SUBCASE("L'epee est contruit et ajouté correctement")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.ajouterEquipement("Epee", 10);
		REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 10);

	}

	SUBCASE("L'armure est contruite et ajoutée correctement")
	{
		int x{ 2 };
		int y{ 4 };
		Position p{ x,y };
		Aventurier a{ p };
		a.ajouterEquipement("Armure", 50);
		REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 50);


	}

}


TEST_CASE("[Aventurier] Aventurier : deplacer selon la touche ")
{
	SUBCASE("l'aventurier est deplacé en haut")
	{

		vector<Cases> T;

		//cout << "\e[8;1000;100S0t";
		Terrain Ter{ 1000,1000,T };
		//Ter.remplirCases();

		system("cls");

		//Ter.ecritTerrain();
		Ter.litTerrain();

		int x{ 1 };
		int y{ 1 };
		Position p{ x,y };
		Aventurier a{ p };
		a.deplacerA(Ter);
		REQUIRE(a.position().x()==x+1);
		REQUIRE(a.position().y() ==y);
	}

	

}

TEST_CASE("[Aventurier] Aventurier : Attaquer le monstre ")
{
	Aventurie a{ Position{1,1},100,100,100, 100, 100 }
	MonstreV m{Position{1,1},100,100,100 }
	a.Attaquer(m)
	SUBCASE("le point de solidite de l'epee  deminue")
	{
		REQUIRE(a.tabEquipement()[1]->pointDeSolidite() == 100-1);
	}

	SUBCASE("le monstre subie des attaque")
	{
		REQUIRE(m.pointDevie() == 0);
	}


*/