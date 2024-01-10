#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED
#include"Position.h"
#include <iostream>

using namespace std;
class Cases {
public:
    Cases(int x, int y);
    Cases(const Position& p);
    virtual ~Cases() ;
    virtual string type() const;
    void setPosition(const Position& p);
    void switchCases(Cases& c);
    Position position() const;
    void deplacer(int x, int y);
private:
    Position d_position;

};
#endif // CASES_H_INCLUDED

