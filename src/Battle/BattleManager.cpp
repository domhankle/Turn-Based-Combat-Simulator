#include "../../include/Battle/BattleManager.h"

BattleManager::BattleManager(Battle& aBattle)
    : currentBattle(aBattle)
{

}

void BattleManager::SetCurrentBattle(Battle& aBattle)
{
    this -> currentBattle = aBattle;
}

Battle BattleManager::GetCurrentBattle() const
{
    return this -> currentBattle;
}