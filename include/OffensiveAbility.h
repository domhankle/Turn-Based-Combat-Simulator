#ifndef OFFENSIVE_ABILITY_H
#define OFFENSIVE_ABILITY_H

#include "Ability.h"

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
class OffensiveAbility : public Ability
{
    private:

        float damage;

    public:

        OffensiveAbility();
        OffensiveAbility(std::string aName, float damageAmount);
        ~OffensiveAbility() override = default;

        float GetDamage() const;
        void SetDamage(float damageAmount);

        void display(std::ostream& outs) const override;
        void LevelUp() override;
        


};



#endif