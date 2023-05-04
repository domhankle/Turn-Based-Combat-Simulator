#include "../../include/Entity/Entity.h"

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


