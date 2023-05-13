#include "../../include/Battle/BattleManager.h"

BattleManager::BattleManager(Battle& aBattle)
    : currentBattle(aBattle), playersTurn(false)
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

void BattleManager::PrintBattleState() const
{
    std::cout << this -> currentBattle.GetEnemy().GetName() << "'s Health: "
              << this ->  currentBattle.GetEnemy().GetHealth() << '\n'
              << '\n' << this -> currentBattle.GetCharacter().GetName() << "'s Health: "
              << this -> currentBattle.GetCharacter().GetHealth() << '\n';
}