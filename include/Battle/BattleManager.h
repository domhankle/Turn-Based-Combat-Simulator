#ifndef BATLLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "Battle.h"
#include "../Ability/Ability.h"
#include "../Ability/OffensiveAbility.h"
#include "../Ability/DefensiveAbility.h"
#include <iostream>
#include <limits>

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
class BattleManager
{
    private:

        Battle currentBattle;
        bool playersTurn;
        int playerChoice;
        

    public:

        BattleManager() = delete;
        BattleManager(Battle& aBattle);
        ~BattleManager() = default;

        void SetCurrentBattle(Battle& aBattle);
        Battle GetCurrentBattle() const;

        void PrintBattleState() const;
        void DisplayCharacterChoices() const;
        void RequestPlayerChoice();

        void InitiateTurn();
        void DamageCharacter(Battle& aBattle, float damage);
        void DamageEnemy(Battle& aEnemy, float damage);
};

#endif