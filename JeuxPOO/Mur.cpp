#include "Mur.h"

Mur::Mur(const Position& position) : Cases{position} 
{}

Mur::Mur(int x, int y) :Cases{ Position{x,y} }
{
}

string Mur::type() const {
	return "Mur";
}