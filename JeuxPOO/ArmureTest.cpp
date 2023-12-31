/*
#include "doctest.h"
#include "Armure.h"

void lesCoordonnesDeLarmureSontCorrectes(const Armure& a, int x) {
	REQUIRE(a.pointDeSolidite() == x);
	REQUIRE(a.typeEquipement() == "Armure");
};

TEST_CASE("[Armure] Armure : Construire une armure") {

	SUBCASE("Le constructeur avec une valeur point de solidité est correct")
	{
		int x = { 100 };
		Armure a1{ x };
		lesCoordonnesDeLarmureSontCorrectes(a1, x);
	}
	SUBCASE("Le constructeur par défault est correct")
	{
		//constructeur par défaut
		Armure a2{};
		lesCoordonnesDeLarmureSontCorrectes(a2, 0);
	
	}
}

TEST_CASE("[Armure] : Armure : modifier les points de solidité de l'armure") {

	SUBCASE("Modifier la solidité par une valeur <= à la solidité")
	{
		int x = { 100 };
		Armure a1{ x };
		a1.ModifierpointDeSolidite(100);
		REQUIRE(a1.pointDeSolidite() == x - 50);
		// L'armure est endomagée

	}
	SUBCASE("Modifier la solidité par une valeur > à la solidité")
	{
		int x = { 100 };
		Armure a1{ x };
		a1.ModifierpointDeSolidite(300);
		REQUIRE(a1.pointDeSolidite() == 0);
		//L'armure est cassé
	}
}
*/