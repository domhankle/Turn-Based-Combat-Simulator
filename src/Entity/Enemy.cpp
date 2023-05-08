#include "../../include/Entity/Entity.h"
#include "../../include/Entity/Enemy.h"

Enemy::Enemy(std::string aName, int numHealthPoints)
    : Entity(aName, numHealthPoints)
{
}

Enemy::Enemy(const Enemy& src)
    : Entity(src.GetName(), src.GetHealth())
{
}

Enemy::~Enemy()
{
    std::cout << "Enemy Object Destroyed.\n";
}

void Enemy::Display(std::ostream& outs) const
{
    outs << this -> GetName() << "\n"
         << "HP: " << this -> GetHealth() << "\n";
}