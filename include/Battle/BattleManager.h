#ifndef BATLLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "Battle.h"
#include <iostream>
#include <limits>

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
};

#endif