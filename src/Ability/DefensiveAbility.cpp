#include "../../include/Ability/DefensiveAbility.h"

DefensiveAbility::DefensiveAbility()
{
    this -> SetName("Default Defensive Ability");
    this -> SetType(false);
}

DefensiveAbility::DefensiveAbility(std::string aName, float resistanceAmount)
    : resistance_points(resistanceAmount)
{
    this -> SetName(aName);
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
    outs << "Name: " << this -> GetName() << "(DEFENSIVE)\n"
         << "Resistance: " << this -> GetResistancePoints() << "\n";
}