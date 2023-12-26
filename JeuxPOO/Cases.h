#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED
#include <iostream>

using namespace std;
class Cases {
public:
    Cases(int x, int y);
    Cases(int x, int y, const string& type);
    void setType(const string& type);
    int x() const;
    int y() const;
    string type() const;
    bool estVide() const;

private:
    int d_x;
    int d_y;
    string d_type;
};

#endif // CASES_H_INCLUDED

