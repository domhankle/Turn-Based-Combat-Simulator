#include "../../include/Battle/BattleGenerator.h"

Battle BattleGenerator::GenerateBattle(Character& aCharacter, Enemy&& anEnemy)
{
    return Battle(aCharacter, anEnemy);
}