#include "MonstreV.h"

void MonstreV::trouverAventurier(Aventurier& A)
{
    // Calcul des différences entre les coordonnées du monstre et de l'aventurier
    int dx = A.pos().x() - pos().x();
    int dy = A.pos().y() - pos().y();

    if ((dx == 1) && (dy == 1))
    {
        attaquer(A);
    }
    else
    {
        if ((abs(dx) == 8) && (abs(dy) == 8))
            {
            // Déplacement du monstre vers l'aventurier
            if (dx > 0)
            {
                // Déplacer vers la droite
                if (dy > 0)
                {
                    if (dx > dy)
                    {
                        deplacer(1, 0);
                    }
                    else
                    {
                        deplacer(0, 1);
                    }
                }
                else
                {
                    if (dx > abs(dy))
                    {
                        deplacer(1, 0);
                    }
                    else
                    {
                        deplacer(0, -1);
                    }

                }
            }
            else
            {
                if (dy > 0)
                {
                    if (abs(dx) > dy)
                    {
                        deplacer(-1, 0);
                    }
                    else
                    {
                        deplacer(0, 1);
                    }
                }
                else
                {
                    if (abs(dx) > abs(dy))
                    {
                        deplacer(-1, 0);
                    }
                    else
                    {
                        deplacer(0, -1);
                    }

                }
            }
        }

        else
        {
        int x = (std::rand() % 3) - 1;
        int y = (std::rand() % 3) - 1;
        deplacer(x, y);
        }
    }
}
