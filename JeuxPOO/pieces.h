#ifndef PIECES_H
#define PIECES_H

#include "Cases.h"




class Pieces : public Cases{
public:
	Pieces(int valeur, Position position);
	int valeur() const;
	string type() const override;
protected:

private:
	int d_valeur;

};



#endif
