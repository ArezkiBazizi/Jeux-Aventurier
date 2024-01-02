#ifndef MONSTREV_H
#define MONSTREV_H
#include "Monstre.h"


class MonstreV : public Monstre
{
public:
    MonstreV(const Position& position, int pointDeVie, int pointDeForce, int pourcentageHabilete);
    void depalcer() override;

    virtual ~MonstreV();

protected:

private:
};

#endif // MONSTREV_H
