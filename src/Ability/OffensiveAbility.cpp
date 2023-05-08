#include "../../include/Ability/OffensiveAbility.h"


OffensiveAbility::OffensiveAbility()
    : Ability("Default Offensive Ability", true), damage(0.0)
{
}

OffensiveAbility::OffensiveAbility(std::string aName, float damageAmount)
    : Ability(aName, true), damage(damageAmount)
{
}

OffensiveAbility::OffensiveAbility(const OffensiveAbility& src)
    : Ability(src), damage(src.GetDamage())
{}

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
