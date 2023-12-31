#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include "string"

using namespace std;

class Equipement
{
public:
    Equipement(int pointDeSolidite);
    virtual ~Equipement() = default;
    virtual int pointDeSolidite() const = 0;
    virtual string typeEquipement() const = 0;
    void ModifierpointDeSolidite(int x);
private:
    int d_pointDeSolidite;
};

#endif // EQUIPEMENT_H
