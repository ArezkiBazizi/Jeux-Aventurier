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
		int pa{ 80 };
		int pe{ 100 };

		Aventurier a{p,v,f,b,pa,pe};
		
		
		REQUIRE(a.position().x() == x);			 //position x
		REQUIRE(a.position().y() == y);			 //position y
		REQUIRE(a.pointDeVie() == v);		 //point de vie
		REQUIRE(a.pointDeForce() == f);		 //point de force
		REQUIRE(a.bourseDePieces() == b);	 //bourse de pieces
		REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == pa);
		REQUIRE(a.tabEquipement()[1]->pointDeSolidite() == pe);


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
		REQUIRE(a.tabEquipement()[0]->pointDeSolidite() == 100);
		REQUIRE(a.tabEquipement()[1]->pointDeSolidite() == 100);
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





TEST_CASE("[Aventurier] Aventurier : deplacer selon la touche ")
{
	SUBCASE("l'aventurier est deplacé en haut")
	{
		
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
	
	SUBCASE("le point de solidite de l'epee  deminue")
	{
		Aventurier a{ Position{1,1},100,30,100, 100, 20 };
		MonstreV m{ Position{1,1},100,100,100 };
		a.Attaquer(m);
		REQUIRE(a.tabEquipement()[1]->pointDeSolidite() == 20- 1);
	}

	SUBCASE("le monstre subie des attaque")
	{	
		Aventurier a{ Position{1,1},100,30,100, 100, 20 };
		MonstreV m{ Position{1,1},100,100,100 };
		a.Attaquer(m);
		int degat{ 100 - (30 + 20)*0.9 };
		REQUIRE(m.pointDeVie() == degat);
	}

	SUBCASE("le monstre et l'aventurier ne sont pas dans la meme case ")
	{
		Aventurier a{ Position{2,1},100,30,100, 100, 20 };
		MonstreV m{ Position{1,1},100,100,100 };
		a.Attaquer(m);
		REQUIRE(m.pointDeVie() == 100);
	}


	SUBCASE("l'aventurier recupere les point de force de monstre ")
	{	
		Aventurier a{ Position{1,1},100,100,100, 100,100};
		MonstreV m{ Position{1,1},100,100,100 };
		a.Attaquer(m);
		REQUIRE(a.pointDeVie() == 175);
		REQUIRE(a.pointDeForce() == 125);

	}

}

TEST_CASE("l'aventurier trouve l'amullette") {
	Terrain ter{};
	ter.litTerrain("map");
	REQUIRE()
}*/