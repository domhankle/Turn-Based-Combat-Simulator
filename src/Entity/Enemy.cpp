#include "../../include/Entity/Entity.h"
#include "../../include/Entity/Enemy.h"

Enemy::Enemy(std::string aName, int numHealthPoints)
{
    this -> SetName(aName);
    this -> SetHealth(numHealthPoints);
}

Enemy::Enemy(const Enemy& src)
{
    this -> SetHealth(src.GetHealth());
    this -> SetName(src.GetName());
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