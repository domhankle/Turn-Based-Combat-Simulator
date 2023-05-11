#include "../../include/Battle/Battle.h"

Battle::Battle(Character& aChar, Enemy& aEnemy)
    : character(aChar), enemy(aEnemy), isDefeated(false)
{
    std::cout << "You've encountered a " << this -> enemy.GetName() << "!\n"
              << "Defeat it before it kills you!\n";
}

Battle::Battle(const Battle& src)
    : character(src.character), enemy(src.enemy), isDefeated(src.isDefeated)
{
    std::cout << "You've encountered a " << this -> enemy.GetName() << "!\n"
              << "Defeat it before it kills you!\n";
}

bool Battle::GetBattleStatus() const
{
    return this -> isDefeated;
}

void Battle::SetBattleStatus(bool aStatus)
{
    this -> isDefeated = aStatus;
}

Battle& Battle::operator=(Battle src)
{
    swap(*this, src);
    return *this;
}

void swap(Battle& lhs, Battle& rhs)
{
    using std::swap;

    swap(lhs.character, rhs.character);
    swap(lhs.enemy, rhs.enemy);
    swap(lhs.isDefeated, rhs.isDefeated);
}
