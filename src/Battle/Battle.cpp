#include "../../include/Battle/Battle.h"

Battle::Battle(Character& aChar, Enemy& aEnemy)
    : character(aChar), enemy(aEnemy), isComplete(false)
{
}

Battle::Battle(const Battle& src)
    : character(src.character), enemy(src.enemy), isComplete(src.isComplete)
{
}

bool Battle::GetBattleStatus() const
{
    return this -> isComplete;
}

void Battle::SetBattleStatus(bool aStatus)
{
    this -> isComplete = aStatus;
}

Character Battle::GetCharacter() const
{
    return character;
}

Enemy Battle::GetEnemy() const
{
    return enemy;
}

void Battle::SetEnemy(Enemy& aEnemy)
{
    this -> enemy = aEnemy;
}

void Battle::SetCharacter(Character& aChar)
{
    this -> character = aChar;
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
    swap(lhs.isComplete, rhs.isComplete);
}
