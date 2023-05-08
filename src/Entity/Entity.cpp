#include "../../include/Entity/Entity.h"

Entity::Entity(std::string aName, int healthAmount)
    : name(aName), health(healthAmount)
{}

Entity::Entity(std::ifstream& input_file)
{
    input_file >> name >> health;
}

std::string Entity::GetName() const
{
    return this -> name;
}

void Entity::SetName(std::string aName)
{
    this -> name = aName;
}

int Entity::GetHealth() const
{
    return this -> health;
}

void Entity::SetHealth(int numHealthPoints)
{
    this -> health = numHealthPoints;
}

void Entity::Display(std::ostream& outs) const
{
    outs << "BASE CLASS DISPLAY CALL\n";
}

