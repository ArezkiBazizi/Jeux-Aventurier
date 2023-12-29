#pragma once
#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position(int x, int y);
    int x() const;
    int y() const;
    void modifierX(int x);
    void modifierY(int y);
    virtual ~Position();


protected:

private:
    int d_x;
    int d_y;
};

#endif // POSITION_H
