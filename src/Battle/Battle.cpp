#include "../../include/Battle/Battle.h"

Battle::Battle(Character& aChar, Enemy& aEnemy)
    : character(aChar), enemy(aEnemy), isDefeated(false)
{
    std::cout << "You've encountered a " << this -> enemy.GetName() << "!\n"
              << "Defeat it before it kills you!\n";
}
