#ifndef OFFENSIVE_ABILITY_H
#define OFFENSIVE_ABILITY_H

#include "Ability.h"

/**
 * @brief A derived class of the abstract base Ability class. This class extends functionality
 *        for offensive abilities that will be used to attack enemies.
 * 
 */
class OffensiveAbility : public Ability
{
    private:

        float damage;

    public:

        /**
         * @brief Construct a new Offensive Ability.
         */
        OffensiveAbility();

        OffensiveAbility(const OffensiveAbility& src);

        /**
         * @brief Construct a new Offensive Ability object with a name and damage amount.
         * 
         * @param aName The name of the new Offensive Ability object.
         * @param damageAmount The amount of damage the Offensive Ability object will do.
         */
        OffensiveAbility(std::string aName, float damageAmount);

        /**
         * @brief Destructor set to default use.
         * 
         */
        ~OffensiveAbility() override = default;

        /**
         * @brief Get the damage that this ability does.
         * 
         * @return the amount of damage this ability does. 
         */
        float GetDamage() const;

        /**
         * @brief Set the amount of damage this ability does.
         * 
         * @param damageAmount the amount of damage to set that this ability does.
         */
        void SetDamage(float damageAmount);

        /**
         * @brief Create a string representation of the object.
         * 
         * @param outs The output stream to send the string representation of this object to.
         */
        void display(std::ostream& outs) const override;

        void extract(std::istream& ins);

        /**
         * @brief Upgrade the abilities stats accordingly.
         * 
         */
        void LevelUp() override;
        


};



#endif