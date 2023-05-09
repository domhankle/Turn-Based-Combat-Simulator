#include "../../include/Ability/DefensiveAbility.h"

DefensiveAbility::DefensiveAbility()
    : Ability("Default Defensive Ability", false), resistance_points(0.0)
{
}

DefensiveAbility::DefensiveAbility(std::string aName, float resistanceAmount)
    : Ability(aName, false), resistance_points(resistanceAmount)
{
}

DefensiveAbility::DefensiveAbility(const DefensiveAbility& src)
    : Ability(src), resistance_points(src.GetResistancePoints())
{}

float DefensiveAbility::GetResistancePoints() const
{
    return this -> resistance_points;
}

void DefensiveAbility::SetResistancePoints(float resistanceAmount)
{
    this -> resistance_points = resistanceAmount;
}

void DefensiveAbility::LevelUp()
{
    std::cout << "Leveling up Defensive Ability...\n";
}

void DefensiveAbility::display(std::ostream& outs) const
{
    outs << "(DEFENSIVE)\n"
         << "Name: " << this -> GetName() << '\n'
         << "Resistance: " << this -> GetResistancePoints() << "\n";
}

void DefensiveAbility::extract(std::istream& ins)
{
    std::string garbage;

    ins >> garbage >> this -> name 
        >> garbage >> this -> resistance_points;
}