#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include "string"

using namespace std;

class Equipement
{
public:

    Equipement(int pointDeSolidite);
    virtual ~Equipement() = default;
    int pointDeSolidite() const;
    virtual string typeEquipement() const = 0;
    void setPointDeSolidite(int x);
    void ModifierpointDeSolidite(int x);


private:
    int d_pointDeSolidite;
};

#endif // EQUIPEMENT_H
