#include "../../include/Ability/Ability.h"

Ability::Ability(std::string aName, bool isOffensiveType)
    : isOffensive(isOffensiveType), name(aName)
{}

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

void Ability::extract(std::istream& ins)
{
    std::string garbage;
    ins >> garbage >> this -> name;
}

void Ability::LevelUp()
{
    std::cout << "Leveling up " << this -> GetName() << "...\n";
}
