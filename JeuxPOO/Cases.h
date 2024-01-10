#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED
#include"Position.h"
#include <iostream>

using namespace std;
class Cases {
public:
    Cases(int x, int y);
    Cases(const Position& p);
    virtual string type() const;
    virtual bool estVide() const;
    Position position() const;
private:
    Position d_position;

};
#endif // CASES_H_INCLUDED

