#include "../../include/Battle/Battle.h"

Battle::Battle(Character& aChar, Enemy& aEnemy)
    : character(aChar), enemy(aEnemy), isDefeated(false)
{
}

Battle::Battle(const Battle& src)
    : character(src.character), enemy(src.enemy), isDefeated(src.isDefeated)
{
}

bool Battle::GetBattleStatus() const
{
    return this -> isDefeated;
}

void Battle::SetBattleStatus(bool aStatus)
{
    this -> isDefeated = aStatus;
}

Character Battle::GetCharacter() const
{
    return character;
}

Enemy Battle::GetEnemy() const
{
    return enemy;
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
