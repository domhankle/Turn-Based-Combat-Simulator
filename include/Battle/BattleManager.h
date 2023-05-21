#ifndef BATLLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "Battle.h"
#include "../Ability/Ability.h"
#include "../Ability/OffensiveAbility.h"
#include "../Ability/DefensiveAbility.h"
#include <iostream>
#include <limits>

/**
 * @brief This class encapsulates the logic of the process of a battle. It handles turn changes,
 *        damage exchanges, and is a gateway into the victory/defeat process of the program.
 * 
 */
class BattleManager
{
    private:

        Battle currentBattle;
        bool playersTurn;
        int playerChoice;
        
    public:

        /**
         * @brief Default constructor is not available for use.
         * 
         */
        BattleManager() = delete;

        /**
         * @brief Construct a new Battle Manager object. There should only be one instance of this
         *        class at a time.
         * 
         * @param aBattle An rvalue reference of a battle object that will be managed.
         */
        BattleManager(Battle&& aBattle);

        /**
         * @brief Destructor set to default
         * 
         */
        ~BattleManager() = default;

        /**
         * @brief Set the Current Battle object to be managed.
         * 
         * @param aBattle The battle object to be managed.
         */
        void SetCurrentBattle(Battle& aBattle);

        /**
         * @brief Get the Current Battle object that is being managed.
         * 
         * @return data about the battle object being managed.
         */
        Battle GetCurrentBattle() const;

        /**
         * @brief Display the current stats of the character and enemy in the battle.
         * 
         */
        void PrintBattleState() const;

        /**
         * @brief Show the ability choices that the character can select for the battle.
         *        If it is character's turn to attack, display only offensive abilities.
         *        If it is enemy's turn to attack, display only defensive abilities.
         * 
         */
        void DisplayCharacterChoices() const;

        /**
         * @brief Request for player input of which ability they would like to use.
         *        This function also handles improper input that is not offered for selection.
         * 
         */
        void RequestPlayerChoice();

        /**
         * @brief Engage attacks and configure Enemy and Character objects to their respective health.
         * 
         */
        void InitiateTurn();
        
        /**
         * @brief Damage the Character object within the battle.
         * 
         * @param aBattle The battle this character object is associated with.
         * @param damage The amount of damage to do to the character.
         */
        void DamageCharacter(Battle& aBattle, float damage);

        /**
         * @brief Damage the Enemy object within the battle.
         * 
         * @param aBattle The battle this enemy object is associated with.
         * @param damage The amount of damage to do to the enemy.
         */
        void DamageEnemy(Battle& aBattle, float damage);

        /**
         * @brief This function is the driver of a battle process. It calls
         *        the associated logic with this class in the proper order to ensure
         *        that a battle is displayed and completed properly.
         * 
         */
        void BattleLoop();
};

#endif