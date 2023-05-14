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

void BattleManager::DisplayCharacterChoices() const
{
    int index = 0;

    if(this -> playersTurn)
    {
        std::cout << "Here is " << this -> currentBattle.GetCharacter().GetName() << "'s attacking options:\n\n";

        for(const std::unique_ptr<Ability>& ability : this -> currentBattle.GetCharacter().GetKnownAbilities())
        {
            if(ability -> IsOffensiveAbiility())
            {
                std::cout << index << ":\n" << *ability;
                ++index;
            }
        }
    }
    else
    {
        std::cout << "Here is " << this -> currentBattle.GetCharacter().GetName() << "'s defensive options:\n\n";
        for(const std::unique_ptr<Ability>& ability : this -> currentBattle.GetCharacter().GetKnownAbilities())
        {
            if(!(ability -> IsOffensiveAbiility()))
            {
                            
                std::cout << index << ":\n" << *ability;
                ++index;
            }
        }
    }
}

void BattleManager::RequestPlayerChoice()
{
    player_decision:

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Make your selection: ";
        std::cin >> playersTurn;

}

void BattleManager::InitiateTurn()
{

}
