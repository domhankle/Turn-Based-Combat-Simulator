#ifndef ABILITY_SET_H
#define ABILITY_SET_H

#include "Ability.h"
#include "OffensiveAbility.h"
#include "DefensiveAbility.h"
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

        AbilitySet(const AbilitySet& src);

        /**
         * @brief Construct a new Ability Set that is a copy of an existing Ability Set. Move constructor
         *        is necessary due to the use of unique_ptr. Note that the previous ability set will get
         *        removed after use of this constructor.
         * 
         * @param src The existing Ability Set that is to be copied.
         */
        AbilitySet(AbilitySet&& src);

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

        /**
         * @brief Extract data from an input stream and configure the values to an Ability Set object.
         * 
         * @param ins The input stream that holds the data.
         */
        void extract(std::istream& ins);

        /**
         * @brief Assignment operator overload for Ability Set objects.
         * 
         * @param rhs The Ability Set we want to assign the current object to.
         * @return A reference to our new Ability object.
         */
        AbilitySet& operator=(AbilitySet rhs);

        /**
         * @brief Friend Function - Used in conjunction with assignment overloader.
         * 
         * @param lhs - Left side of Obj1 = Obj2
         * @param rhs - Right side of Obj1 = Obj2
         */
        friend
        void swap(AbilitySet& lhs, AbilitySet& rhs);


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

inline
std::istream& operator>>(std::istream& ins, AbilitySet& src)
{
    src.extract(ins);
    return ins;
}

#endif