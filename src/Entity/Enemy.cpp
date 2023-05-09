#include "../../include/Entity/Entity.h"
#include "../../include/Entity/Enemy.h"

Enemy::Enemy(std::string aName, int numHealthPoints, float damageAmount)
    : Entity(aName, numHealthPoints), damage(damageAmount)
{
}

Enemy::Enemy(const Enemy& src)
    : Entity(src.GetName(), src.GetHealth()), damage(src.GetDamage())
{
}


Enemy::~Enemy()
{
    std::cout << "Enemy Object Destroyed.\n";
}


void Enemy::Display(std::ostream& outs) const
{
    outs << this -> GetName() << '\n'
         << "HP: " << this -> GetHealth() << '\n'
         << "DMG: " << this -> GetDamage() << '\n';
}

void Enemy::Extract(std::istream& ins)
{
    ins >> this -> name >> this -> health >> this -> damage;
}

void Enemy::SetDamage(float damageAmount)
{
    this -> damage = damageAmount;
}

float Enemy::GetDamage() const
{
    return this -> damage;
}