/*

#include "doctest.h"
#include "Equipement.h"

TEST_CASE("[Equipement] Initialisation des points de solidit� et modification") {
    Equipement equip{ 50 };

    SUBCASE("Initialisation des points de solidit�") {
        CHECK(equip.pointDeSolidite() == 50);
    }

    SUBCASE("Modification des points de solidit� avec une valeur <= � la solidit�") {
        equip.ModifierpointDeSolidite(30);
        CHECK(equip.pointDeSolidite() == 35);
    }

    SUBCASE("Modification des points de solidit� avec une valeur > � la solidit�") {
        equip.ModifierpointDeSolidite(70);
        CHECK(equip.pointDeSolidite() == 0);
    }
}
*/