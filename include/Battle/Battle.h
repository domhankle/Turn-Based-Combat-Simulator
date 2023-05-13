#ifndef BATTLE_H
#define BATTLE_H

#include "../Entity/Character.h"
#include "../Entity/Enemy.h"
#include "../Entity/EntityGenerator.h"

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
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

        Battle(const Battle& src);

        Battle& operator=(Battle src);

        bool GetBattleStatus() const;
        void SetBattleStatus(bool aStatus);

        Character GetCharacter() const;
        Enemy GetEnemy() const;

        friend
        void swap(Battle& lhs, Battle& rhs);

};


#endif