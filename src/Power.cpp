#include "../include/Power.h"

Power::Power(std::string aName, bool aBool)
{
    this -> isOffensive = aBool;
    this -> name = aName;
}

std::string Power::GetName() const
{
    return this -> name;
}

void Power::SetName(std::string aName)
{
    this -> name = aName;
}
