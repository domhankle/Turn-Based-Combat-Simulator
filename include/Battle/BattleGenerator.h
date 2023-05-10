#ifndef BATTLE_GENERATOR_H
#define BATTLE_GENERATOR_H

#include "Battle.h"

class BattleGenerator
{
    static Battle GenerateBattle(Character& aChar, Enemy& aEnemy);
};

#endif