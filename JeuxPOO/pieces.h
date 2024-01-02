#ifndef PIECES_H
#define PIECES_H

#include "Position.h"




class Pieces{
public:
	Pieces(int valeur, Position position);
	int valeur() const;
	Position position() const;
protected:

private:
	int d_valeur;
	Position d_position;

};



#endif
