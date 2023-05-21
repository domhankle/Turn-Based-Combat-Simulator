#include "../../include/Battle/BattleGenerator.h"

Battle BattleGenerator::GenerateBattle(Character& aCharacter, int stage)
{
    Enemy enemy_to_battle = EntityGenerator::GenerateEnemy(stage);
    return Battle(aCharacter, enemy_to_battle);
}