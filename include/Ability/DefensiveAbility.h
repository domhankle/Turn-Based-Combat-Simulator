#ifndef DEFENSIVE_ABILITY_H
#define DEFENSIVE_ABILITY_H

#include "Ability.h"

/**
 * @brief This class inherits from the abstract base class Ability. It represents
 *        defensive techniques that the character will use to defend themselves from Enemy attacks.
 * 
 */
class DefensiveAbility : public Ability
{   

    private:

        float resistance_points;

    public:

        /**
         * @brief Construct a new default Defensive Ability object
         * 
         */
        DefensiveAbility();

        /**
         * @brief Construct a new Defensive Ability object that is a copy of an existing
         *        Defensive Ability object.
         * 
         * @param src The existing Defensive Ability object to copy.
         */
        DefensiveAbility(const DefensiveAbility& src);

        /**
         * @brief Construct a new Defensive Ability object with a custom name and resistance level.
         * 
         * @param aName Name of the new Defensive Ability object.
         * @param resistanceAmount Resistance level of the new Defensive Ability object.
         */
        DefensiveAbility(std::string aName, float resistanceAmount);

        /**
         * @brief Destructor set to default use.
         * 
         */
        ~DefensiveAbility() override = default;

        /**
         * @brief Create a string representation of a Defensive Ability object.
         * 
         * @param outs The output stream to send the string representation to.
         */
        void display(std::ostream& outs) const override;

        void extract(std::istream& ins) override;

        /**
         * @brief Every Defensive Ability object has an opportunity to improve it's overall stats.
         * 
         */
        void LevelUp() override;
        
        /**
         * @brief Get the Resistance Points of the Defensive Ability object.
         * 
         * @return The resistance level of the Defensive Ability object. 
         */
        float GetResistancePoints() const;

        /**
         * @brief Set the Resistance Points of the Defensive Ability object.
         * 
         * @param resistanceAmount The resistance level to set this Defensive ability object to have.
         */
        void SetResistancePoints(float resistanceAmount);

};

#endif