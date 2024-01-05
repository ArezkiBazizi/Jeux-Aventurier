#include "Pieces.h"

Pieces::Pieces(int valeur, Position position): d_valeur{valeur}, d_position{position}
{}

int Pieces::valeur() const{
	return d_valeur;
}

Position Pieces::position() const{
	return d_position;
}