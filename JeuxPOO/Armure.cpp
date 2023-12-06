#ifndef ARMURE_H
#define ARMURE_H
#include "Equipement.h"
#include "string"


class Armure : public Equipement
{
public:
    Armure(int pointDeSolidite);
    int pointDeSolidite() const override;
    virtual string typeEquipement() const override;
    void ModifierpointDeSolidite(int Valeur) override;
    virtual ~Armure();

protected:

private:
    int d_pointDeSolidite;
};

#endif // ARMURE_H
