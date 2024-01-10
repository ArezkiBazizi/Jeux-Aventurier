#pragma once
#include "Cases.h"
class VideC :
    public Cases
{

    VideC(int x, int y);
    string type() const override;
};

