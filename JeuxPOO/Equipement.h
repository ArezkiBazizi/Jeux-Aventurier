#pragma once
#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include "string"

using namespace std;

class Equipement
{
public:
    virtual ~Equipement();
    virtual int pointDeSolidite() const = 0;
    virtual string typeEquipement() const = 0;
    virtual void ModifierpointDeSolidite(int Valeur) = 0;
private:
};

#endif // EQUIPEMENT_H
