#ifndef BATTLE_H
#define BATTLE_H

#include "../Entity/Character.h"
#include "../Entity/Enemy.h"
#include "../Entity/EntityGenerator.h"

/**
 * @brief This class encapsulates an interaction between a character and an enemy. It mainly
 *        holds the data rather than the logic/processing of the interaction.
 * 
 */
class Battle
{

    private:

        Character character;
        Enemy enemy;
        bool isComplete;

    public:

        /**
         * @brief Default Constructor is not available for use.
         * 
         */
        Battle() = delete;

        /**
         * @brief Construct a new Battle object from a Character and Enemy object. isComplete
         *        attribute will always be set to false originally with this constructor.
         * 
         * @param aChar The character in this battle.
         * @param aEnemy The enemy in this battle.
         */
        Battle(Character& aChar, Enemy& aEnemy);

        /**
         * @brief Destructor set to default use.
         * 
         */
        ~Battle() = default;

        /**
         * @brief Construct a new Battle object from an existing Battle object.
         * 
         * @param src The existing battle object to copy.
         */
        Battle(const Battle& src);

        /**
         * @brief Assignment operator overload for Battle objects.
         * 
         * @param src The Battle object to assign. 
         * @return A reference to the battle object data that will be assigned.
         */
        Battle& operator=(Battle src);

        /**
         * @brief Determine whether or not the battle is completed.
         * 
         * @return true - The battle is complete.
         * @return false - The battle is not complete.
         */
        bool GetBattleStatus() const;

        /**
         * @brief Change whether or not the battle is completed.
         * 
         * @param aStatus true = battle is complete, false = battle is not complete.
         */
        void SetBattleStatus(bool aStatus);

        /**
         * @brief Get the Character object that is associated with the Battle 
         * 
         * @return the Character data that is in the battle.
         */
        Character GetCharacter() const;

        /**
         * @brief Get the Enemy object that is associated with the Battle
         * 
         * @return the Enemy data that is in the battle.
         */
        Enemy GetEnemy() const;

        /**
         * @brief Set the Character object in the battle.
         * 
         * @param aChar The character object to configure to the battle.
         */
        void SetCharacter(Character& aChar);

        /**
         * @brief Set the Enemy object in the battle.
         * 
         * @param aEnemy The enemy object to configure to the battle.
         */
        void SetEnemy(Enemy& aEnemy);

        /**
         * @brief Helper function for the assignment overloader.
         * 
         * @param lhs The battle object to assign to.
         * @param rhs The battle object to be assigned.
         */
        friend
        void swap(Battle& lhs, Battle& rhs);

};


#endif