#include "MonstreV.h"

void MonstreV::trouverAventurier(const Aventurier& A)
{
		
	if((abs((pos().x()) - (A.pos().x()))==8) && (abs((pos().y()) - (A.pos().y())) == 8))
		{
				
        // Calcul des différences entre les coordonnées du monstre et de l'aventurier
        int dx = A.pos().x() - pos().x();
        int dy = A.pos().y() - pos().y();

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


		}
	else
		{
		int x = (std::rand() %3) - 1;
		int y = (std::rand() %3) - 1;
		this.deplacer(x, y);
		}



};
