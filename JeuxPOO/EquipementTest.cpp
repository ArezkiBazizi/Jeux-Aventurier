/*

#include "doctest.h"
#include "Equipement.h"

TEST_CASE("[Equipement] Initialisation des points de solidité et modification") {
    Equipement equip{ 50 };

    SUBCASE("Initialisation des points de solidité") {
        CHECK(equip.pointDeSolidite() == 50);
    }

    SUBCASE("Modification des points de solidité avec une valeur <= à la solidité") {
        equip.ModifierpointDeSolidite(30);
        CHECK(equip.pointDeSolidite() == 35);
    }

    SUBCASE("Modification des points de solidité avec une valeur > à la solidité") {
        equip.ModifierpointDeSolidite(70);
        CHECK(equip.pointDeSolidite() == 0);
    }
}
*/