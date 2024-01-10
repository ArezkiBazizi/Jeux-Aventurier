#include "Vide.h"

Vide::Vide(int x, int y):
	Cases{ x,y }
{}

string Vide::type() const
{
	return "Vide";
}