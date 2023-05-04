#ifndef DEFENSIVE_ABILITY_H
#define DEFENSIVE_ABILITY_H

#include "Ability.h"

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
class DefensiveAbility : public Ability
{   

    private:

        float resistance_points;

    public:

        DefensiveAbility();

        DefensiveAbility(const DefensiveAbility& src);

        DefensiveAbility(std::string aName, float resistanceAmount);

        ~DefensiveAbility() override = default;

        void display(std::ostream& outs) const override;

        void LevelUp() override;

        float GetResistancePoints() const;

        void SetResistancePoints(float resistanceAmount);

};

#endif