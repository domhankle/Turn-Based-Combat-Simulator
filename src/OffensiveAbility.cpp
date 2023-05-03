#include "../include/OffensiveAbility.h"


OffensiveAbility::OffensiveAbility()
    : damage(0.0)
{
    this -> SetName("Default Name");
    this -> SetType(true);
}

OffensiveAbility::OffensiveAbility(std::string aName, float damageAmount)
    : damage(damageAmount)
{
    this -> SetName(aName);
    this -> SetType(true);
}

void OffensiveAbility::display(std::ostream& outs) const
{
    outs << "Name: " << this -> GetName() << " (OFFENSIVE)\n"
         << "Damage: " << this -> GetDamage() << '\n';
}

void OffensiveAbility::LevelUp()
{
    this -> SetDamage(this -> GetDamage() + 3.5);
    std::cout << this -> GetName() << " is leveling up!\n"
              << "It now does " << this -> GetDamage() << " damage!\n";
}

float OffensiveAbility::GetDamage() const
{
    return this -> damage;
}

void OffensiveAbility::SetDamage(float damageAmount)
{
    this -> damage = damageAmount;
}
