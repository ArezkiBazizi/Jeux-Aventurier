/*
#include "doctest.h"
#include "Position.h"

void lesCoordonnesSontCorrectes(const Position& p, int x, int y) {
	REQUIRE(p.x() == x);
	REQUIRE(p.y() == y);
};

TEST_CASE("[Position] Position : Construire une position") {

	SUBCASE("Le constructeur de position")
	{
		int x = { 2 };
		int y = { 5 };
		Position p{x,y};
		lesCoordonnesSontCorrectes(p, x, y);
	}

}

TEST_CASE("[Position] Position :  modifier une position") {

	SUBCASE("modifier le 'x'")
	{
		int x = { 2 };
		int y = { 5 };
		Position p{ x,y };
		p.modifierX(1);
		lesCoordonnesSontCorrectes(p, x + 1, y);
	}
	SUBCASE("modifier le 'y'")
	{
		int x = { 2 };
		int y = { 5 };
		Position p{ x,y };
		p.modifierY(-2);
		lesCoordonnesSontCorrectes(p, x, y - 2);

	}

}
*/