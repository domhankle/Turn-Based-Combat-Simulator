#ifndef ABILITY_SET_H
#define ABILITY_SET_H

#include "Ability.h"
#include <vector>
#include <memory>

/**
 * @brief The data structure that holds the abilities which an Entity has.
 * 
 */
class AbilitySet
{
    public:

        using iterator = std::vector<std::unique_ptr<Ability>>::iterator;
        using const_iterator = std::vector<std::unique_ptr<Ability>>::const_iterator;

    private:

        std::vector<std::unique_ptr<Ability>> knownAbilities;
    
    public:

        /**
         * @brief Construct a new Ability Set.
         * 
         */
        AbilitySet();

        /**
         * @brief Destructor set to default use.
         * 
         */
        ~AbilitySet() = default;

        /**
         * @brief Construct a new Ability Set that is a copy of an existing Ability Set.
         * 
         * @param src The existing Ability Set that is to be copied.
         */
        AbilitySet(const AbilitySet& src);

        /**
         * @brief Get a reference to the first ability in the Ability Set.
         * 
         * @return A reference to the first ability in the Ability Set. 
         */
        iterator begin();

        /**
         * @brief Get a reference to the last ability in the Ability Set.
         * 
         * @return A reference to the last ability in the Ability Set. 
         */
        iterator end();

        /**
         * @brief Get a constant reference to the first ability in the Ability Set.
         * 
         * @return A constant reference to the first ability in the Ability Set. 
         */
        const_iterator begin() const;

        /**
         * @brief Get a constant reference to the last ability in the Ability Set.
         * 
         * @return A constant reference to the last ability in the Ability Set. 
         */
        const_iterator end() const;

        /**
         * @brief Add an ability to the Ability Set.
         * 
         * @param to_add The ability that you would like to add to the Ability Set.
         */
        void add(std::unique_ptr<Ability> to_add);

        /**
         * @brief Create a string representation of the Ability Set.
         * 
         * @param outs The output stream that the string representation will be sent to.
         */
        void display(std::ostream& outs) const;

};

/**
 * @brief Stream insertion operator overload for AbilitySet.
 * 
 * @param outs The output stream to send the string representation to.
 * @param src The Ability Set we want the string representation of.
 * @return the output stream (outs) that now contains the string representation of src.
 */
inline
std::ostream& operator<<(std::ostream& outs, const AbilitySet& src)
{
    src.display(outs);
    return outs;
}

#endif