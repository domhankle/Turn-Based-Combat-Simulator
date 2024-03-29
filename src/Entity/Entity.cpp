#include "../../include/Entity/Entity.h"

Entity::Entity(std::string aName, int healthAmount)
    : name(aName), health(healthAmount)
{}

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

void Entity::Extract(std::istream& ins)
{
    ins >> this -> name >> this -> health;
}

