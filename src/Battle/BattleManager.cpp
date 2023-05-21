#include "../../include/Battle/BattleManager.h"

BattleManager::BattleManager(Battle&& aBattle)
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

    std::cout << "Hit any key to continue...\n";
    std::cin.get();
}

void BattleManager::BattleLoop()
{
    while(!(this -> GetCurrentBattle().GetBattleStatus()))
    {
        this -> PrintBattleState();
        this -> DisplayCharacterChoices();
        this -> RequestPlayerChoice();
        this -> InitiateTurn();
    }

    system("clear");
    if(this -> GetCurrentBattle().GetEnemy().GetHealth() > 0)
    {
        std::cout << "The " << this -> GetCurrentBattle().GetEnemy().GetName() << " defeated "
                  << this -> GetCurrentBattle().GetCharacter().GetName() << ".\n"
                  << "Try again with a new character!\n";
        system(EXIT_SUCCESS);
    }
    else
    {
        std::cout << "You've defeated the " << this -> GetCurrentBattle().GetEnemy().GetName() << "!\n";
    }

    std::cout << "Hit any key to continue...\n";
    std::cin.get();
}

void BattleManager::DisplayCharacterChoices() const
{
    int index = 0;

    if(this -> playersTurn)
    {
        std::cout << "The " << this -> currentBattle.GetEnemy().GetName() << " has "
                  << this -> currentBattle.GetEnemy().GetHealth() << " HP left!\n"
                  << "Here is " << this -> currentBattle.GetCharacter().GetName() << "'s attacking options:\n\n";

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
        std::cout << "The " << this -> currentBattle.GetEnemy().GetName() << " can do up to "
                  << this -> currentBattle.GetEnemy().GetDamage() << " damage, defend yourself!\n"
                  << "Here is " << this -> currentBattle.GetCharacter().GetName() << "'s defensive options:\n\n";
                  
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

        std::cout << "\nMake your selection: ";
        std::cin >> this -> playerChoice;
    if(std::cin.bad())
    {
        goto player_decision;
    }

    system("clear");

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
            if(abilityPtr -> IsOffensiveAbiility())
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

    if(aBattle.GetEnemy().GetHealth() <= 0 || aBattle.GetCharacter().GetHealth() <= 0)
    {
        aBattle.SetBattleStatus(true);
    }

    this -> SetCurrentBattle(aBattle);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void BattleManager::DamageCharacter(Battle& aBattle, float damage)
{
    if(damage <= 0)
    {
        return;
    }

    Character tempChar(aBattle.GetCharacter());
    tempChar.SetHealth(tempChar.GetHealth() - damage);

    aBattle.SetCharacter(tempChar);
}

void BattleManager::DamageEnemy(Battle& aBattle, float damage)
{
    if(damage <= 0)
    {
        return;
    }

    Enemy tempEnemy(aBattle.GetEnemy());
    tempEnemy.SetHealth(tempEnemy.GetHealth() - damage);

    aBattle.SetEnemy(tempEnemy);
}