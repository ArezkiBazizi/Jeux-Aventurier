/*
// testCases.cpp

#include "doctest.h"
#include "Cases.h"

TEST_CASE("[Cases] Initialisation de la position et type") {
    Cases cases{ 1, 2 };

    SUBCASE("Initialisation de la position") {
        CHECK(cases.position().x() == 1);
        CHECK(cases.position().y() == 2);
    }

    SUBCASE("Initialisation du type") {
        CHECK(cases.type() == "Cases");
    }
}

TEST_CASE("[Cases] Modification de la position") {
    Cases cases{ 1, 2 };

    SUBCASE("Changement de position avec une nouvelle position") {
        Position newPosition{ 3, 4 };
        cases.setPosition(newPosition);
        CHECK(cases.position() == newPosition);
    }

    SUBCASE("D�placement de la position avec des coordonn�es") {
        cases.deplacer(5, 6);
        CHECK(cases.position().x() == 6);
        CHECK(cases.position().y() == 8);
    }

    SUBCASE("�change de positions avec une autre instance de Cases") {
        Cases otherCases{ 7, 8 };
        cases.switchCases(otherCases);
        CHECK(cases.position() == Position{7, 8});
        CHECK(otherCases.position() == Position{1, 2});
    }
}

TEST_CASE("[Cases] Op�rateurs d'assignation et d'�galit�") {
    Cases cases1{ 1, 2 };
    Cases cases2{ 3, 4 };
    cases2 = cases1;

    SUBCASE("Op�rateur d'assignation") {
        CHECK(cases2.position() == cases1.position());
    }

    SUBCASE("Op�rateur d'�galit�") {
        CHECK(cases1 == cases2);
    }
}
*/