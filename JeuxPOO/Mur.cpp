#include "Mur.h"

Mur::Mur(const Position& position) : Cases{position} 
{}

string Mur::type() const {
	return "Mur";
}