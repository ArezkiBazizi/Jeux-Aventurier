#pragma once
#ifndef EPEE_H
#define EPEE_H
#include "Equipement.h"


class Epee : public Equipement
{
public:
    Epee(int pointDeSolidite);
    int pointDeSolidite() const override;
    string typeEquipement() const override;

protected:

private:
};

#endif // EPEE_H
