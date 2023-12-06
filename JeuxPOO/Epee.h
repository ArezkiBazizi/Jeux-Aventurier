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
    virtual ~Epee();

protected:

private:
    int d_pointDeSolidite;
};

#endif // EPEE_H
