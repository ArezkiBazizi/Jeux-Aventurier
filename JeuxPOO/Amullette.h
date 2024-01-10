#pragma once
#include"Cases.h"

class Amullette : public Cases
{
public:
	Amullette(const Position& position);
	string type() const override;
};

