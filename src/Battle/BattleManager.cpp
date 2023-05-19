#include "../../include/Battle/BattleManager.h"

void DamageCharacter(float damage);

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

        std::cout << "Make your selection: ";
        std::cin >> this -> playerChoice;
    
    if(std::cin.bad())
    {
        goto player_decision;
    }

}

void BattleManager::InitiateTurn()
{
    int count = -1;

    if(!playersTurn)
    {
        for(std::unique_ptr<Ability>& abilityPtr : this -> GetCurrentBattle().GetCharacter().GetKnownAbilities())
        {
            if(!(abilityPtr -> IsOffensiveAbiility()))
            {
                count++;
            }

            if(count == this -> playerChoice)
            {
                DefensiveAbility abilityToUse(dynamic_cast<DefensiveAbility&>(*abilityPtr));
                this -> DamageCharacter(this -> GetCurrentBattle().GetEnemy().GetDamage() - abilityToUse.GetResistancePoints());
                break;
            }
        }
    }
    else
    {
        std::cout << this -> GetCurrentBattle().GetCharacter().GetKnownAbilities();
    }
}

void BattleManager::DamageCharacter(float damage)
{
    if(damage <= 0)
    {
        return;
    }
    this -> GetCurrentBattle().GetCharacter().SetHealth(this -> GetCurrentBattle().GetCharacter().GetHealth() - damage);
}

void BattleManager::DamageEnemy(float damage)
{

}