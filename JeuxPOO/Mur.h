#pragma once
#include "Cases.h"

class Mur : public Cases
{
	Mur(const Position& position);
	string type() const override;
};

