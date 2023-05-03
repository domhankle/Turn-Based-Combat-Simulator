#include "../include/Ability.h"

std::string Ability::GetName() const
{
    return this -> name;
}

void Ability::SetName(std::string aName)
{
    this -> name = aName;
}

bool Ability::IsOffensiveAbiility() const
{
    return this -> isOffensive;
}

void Ability::SetType(bool offensiveType)
{
    this -> isOffensive = offensiveType;
}

void Ability::display(std::ostream& outs) const
{
    outs << "BASE CLASS DISPLAY CALL\n";
}
