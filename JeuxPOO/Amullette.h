#pragma once
#include"Cases.h"

class Amullette : public Cases
{
public:
	Amullette(const Position& position);
	bool etatAmullette() const;
	void changeEtatAllumettes(const bool e);
	string type() const override;

private:
	bool d_etat{ false };
};

