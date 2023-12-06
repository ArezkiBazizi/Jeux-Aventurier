#ifndef ARMURE_H
#define ARMURE_H
#include "Equipement.h"
#include "string"


class Armure : public Equipement
{
public:
    Armure(int pointDeSolidite);
    int pointDeSolidite() const override;
    string typeEquipement() const override;
    void ModifierpointDeSolidite(int Valeur) override;

protected:

private:

};

#endif // ARMURE_H
