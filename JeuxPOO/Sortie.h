#pragma once
#include "Cases.h"
class Sortie : public Cases
{
public:
	Sortie(int x, int y);
	string type() const override;
};

