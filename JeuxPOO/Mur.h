#pragma once
#include "Cases.h"

class Mur : public Cases
{
public:

	Mur(int x, int y);
	Mur(const Position& position);
	string type() const override;
};

