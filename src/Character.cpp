#include "../include/Character.h"

Character::Character(std::string aName)
    : level(1)
{
    this -> SetName(aName);
    this -> SetHealth(100);
}

Character::~Character()
{
    std::cout << "Character Object Destroyed.\n";
}

Character::Character(const Character& src)
    : level(src.GetLevel())
{
    this -> SetName(src.GetName());
    this -> SetHealth(src.GetHealth());
}

int Character::GetLevel() const
{
    return this -> level;
}

void Character::SetLevel(int aLevel)
{
    this -> level = aLevel;
}

void Character::Display(std::ostream& outs) const 
{
    outs << this -> GetName() << "\n"
         << "HP: " << this -> GetHealth() << "\n"
         << "Level: " << this -> GetLevel() << "\n";
}

