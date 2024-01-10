#include "Pieces.h"

Pieces::Pieces(int valeur, Position position): Cases{ position }, d_valeur{valeur}
{}

int Pieces::valeur() const{
	return d_valeur;
}

string Pieces::type() const
{
	return "Pieces";
}

