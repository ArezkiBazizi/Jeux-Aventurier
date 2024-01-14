#include "Amullette.h"

Amullette::Amullette(const Position& position): Cases{position}
{}


string Amullette::type() const
{
	return "Amullette";
}

bool Amullette::etatAmullette() const
{
	return d_etat;
}
void Amullette::changeEtatAllumettes(bool e)
{
	d_etat = e;
}

