#include "MonstreV.h"

void MonstreV::trouverAventurier(Aventurier& A)
{
    // Calcul des différences entre les coordonnées du monstre et de l'aventurier
    int dx = A.position().x() - position().x();
    int dy = A.position().y() - position().y();

    if ((dx == 1) && (dy == 1))
    {
        attaquer(A);
    }

    else if (abs(dx) == 8 && abs(dy) == 8)
    {
        deplacerVersAventurier(dx, dy);
    }
    else
    {
        int x = (std::rand() % 3) - 1;
        int y = (std::rand() % 3) - 1;
        deplacer(x, y);
    }

}

void deplacerVersAventurier(int dx, int dy) {


    // Générer les 4 cases possibles en ordre décroissant de proximité
    std::pair<int, int> casesPossibles[4] = {
        {position().x() + 1, position().y()}, // Droite
        {position().x() - 1, position().y()}, // Gauche
        {position().x(), position().y() + 1}, // Haut
        {position().x(), position().y() - 1}  // Bas
    };

    std::sort(std::begin(casesPossibles), std::end(casesPossibles), [&](const auto& a, const auto& b) {
        int distA = std::abs(a.first - position().x() - dx) + std::abs(a.second - position().y() - dy);
        int distB = std::abs(b.first - position().x() - dx) + std::abs(b.second - position().y() - dy);
        return distA < distB; // Tri croissant
        });


    for (const auto& casePossible : casesPossibles) {
        int newX = casePossible.first;
        int newY = casePossible.second;

        if (Cases(newX, newY).estVide()) {
            deplacer(newX - position().x(), newY - position().y());
            break; // Sortir de la boucle une fois le déplacement effectué
        }
    }


}