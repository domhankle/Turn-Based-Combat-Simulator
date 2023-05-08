#include "../../include/Entity/Character.h"

Character::Character(std::string aName)
    : Entity(aName, 100), level(1)
{}

Character::Character(std::ifstream& input_file)
    : Entity(input_file)
{
    input_file >> level;
}

Character::~Character()
{
    std::cout << "Character Object Destroyed.\n";
}

Character::Character(const Character& src)
    : Entity(src.GetName(), src.GetHealth()), level(src.GetLevel())
{
}

int Character::GetLevel() const
{
    return this -> level;
}

void Character::SetLevel(int aLevel)
{
    this -> level = aLevel;
}

void Character::LearnAbility(Ability&& src)
{
    
    if(src.IsOffensiveAbiility())
    {
        this -> abilities_known.add(std::make_unique<OffensiveAbility>(dynamic_cast<OffensiveAbility&>(src)));
    }
    else if(!(src.IsOffensiveAbiility()))
    {
        this -> abilities_known.add(std::make_unique<DefensiveAbility>(dynamic_cast<DefensiveAbility&>(src)));
    }
    
}

void Character::Display(std::ostream& outs) const 
{
    outs << this -> GetName() << "\n"
         << "HP: " << this -> GetHealth() << "\n"
         << "Level: " << this -> GetLevel() << "\n\n"
         << "ABILITIES:\n"
         << this -> abilities_known;
}

