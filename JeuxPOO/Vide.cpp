#include "Vide.h"

Vide::Vide(int x, int y):
	Cases{ x,y }
{}

Vide::estVide() const
{
	return true;
}
