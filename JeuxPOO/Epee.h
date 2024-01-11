#pragma once
#ifndef EPEE_H
#define EPEE_H
#include "Equipement.h"


class Epee : public Equipement
{
public:
    Epee();
    Epee(int pointDeSolidite);
    string typeEquipement() const override;
    ~Epee();
protected:

private:
};

#endif // EPEE_H
