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
        std::cin.clear();
    if(std::cin.bad())
    {
        goto player_decision;
    }

}

void BattleManager::InitiateTurn()
{
    int count = -1;
    Battle aBattle(this -> GetCurrentBattle());

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
                this -> DamageCharacter(aBattle,
                                        this -> GetCurrentBattle().GetEnemy().GetDamage() 
                                        - abilityToUse.GetResistancePoints());
                break;
            }
        }

        this -> playersTurn = true;
    }
    else
    {
        for(std::unique_ptr<Ability>& abilityPtr : this -> GetCurrentBattle().GetCharacter().GetKnownAbilities())
        {
            if(!(abilityPtr -> IsOffensiveAbiility()))
            {
                count++;
            }

            if(count == this -> playerChoice)
            {
                OffensiveAbility abilityToUse(dynamic_cast<OffensiveAbility&>(*abilityPtr));
                this -> DamageEnemy(aBattle, abilityToUse.GetDamage());
                break;
            }
        }

        this -> playersTurn = false;
    }

    this -> SetCurrentBattle(aBattle);
}

void BattleManager::DamageCharacter(Battle& aBattle, float damage)
{

    if(damage <= 0)
    {
        return;
    }
    aBattle.SetCharacter(Character(aBattle.GetCharacter().GetName(), 
                         aBattle.GetCharacter().GetHealth() - damage, 
                         aBattle.GetCharacter().GetLevel()));
    
}

void BattleManager::DamageEnemy(Battle& aBattle, float damage)
{
    if(damage <= 0)
    {
        return;
    }
    aBattle.SetEnemy(Enemy(aBattle.GetEnemy().GetName(),
                     aBattle.GetEnemy().GetHealth() - damage,
                     aBattle.GetEnemy().GetDamage()));
}