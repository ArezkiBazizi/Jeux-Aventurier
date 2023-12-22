#pragma once
#ifndef EPEE_H
#define EPEE_H
#include "Equipement.h"


class Epee : public Equipement
{
public:
    Epee(int pointDeSolidite);
    string typeEquipement() const override;
    virtual ~Epee();
protected:

private:
};

#endif // EPEE_H
