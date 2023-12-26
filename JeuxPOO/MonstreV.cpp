#include "MonstreV.h"

void MonstreV::trouverAventurier(const Aventurier& A)
{
		
	if (abs(this.position().x() - A.position().x())= 8) && (abs(position().y() - A.position().y())= 8)
		{
			
		}
	else
		{
		int x = (std::rand() %3) - 1;
		int y = (std::rand() %3) - 1;
		this.deplacer(x, y);
		}



};
