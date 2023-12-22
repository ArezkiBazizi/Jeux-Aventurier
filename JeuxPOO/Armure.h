#ifndef ARMURE_H
#define ARMURE_H
#include "Equipement.h"
#include <string>


class Armure : public Equipement
{
public:
    Armure(int pointDeSolidite);
    string typeEquipement() const override;
    virtual ~Armure();
protected:

private:

};

#endif // ARMURE_H
