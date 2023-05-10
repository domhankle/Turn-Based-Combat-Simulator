#ifndef BATTLE_H
#define BATTLE_H

#include "../Entity/Character.h"
#include "../Entity/Enemy.h"
#include "../Entity/EntityGenerator.h"

class Battle
{

    private:

        Character character;
        Enemy enemy;
        bool isDefeated;

    public:

        Battle() = delete;
        Battle(Character& aChar, Enemy& aEnemy);
        ~Battle() = default;



};

#endif