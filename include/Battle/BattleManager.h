#ifndef BATLLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "Battle.h"

class BattleManager
{
    private:

        Battle currentBattle;

    public:

        BattleManager() = delete;
        BattleManager(Battle& aBattle);
        ~BattleManager() = default;

        void SetCurrentBattle(Battle& aBattle);
        Battle GetCurrentBattle() const;        
};

#endif