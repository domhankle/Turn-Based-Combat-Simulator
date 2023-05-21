#ifndef BATTLE_GENERATOR_H
#define BATTLE_GENERATOR_H

#include "Battle.h"
#include "../Entity/EntityGenerator.h"

/**
 * @brief This is a class full of static functions, which will be a utility for creating
 *        Battle objects.
 * 
 */
class BattleGenerator
{
    public:

        /**
         * @brief Constructor not available for use. This class should not be instantiated.
         * 
         */
        BattleGenerator() = delete;

        /**
         * @brief The static function which will generate a battle from a character and
         *        stage input.
         * 
         * @param aChar The character in the battle.
         * @param stage Stage level the character is at.
         * @return A battle that involves the character and a random enemy from specified stage.
         */
        static Battle GenerateBattle(Character& aChar, int stage);
};

#endif