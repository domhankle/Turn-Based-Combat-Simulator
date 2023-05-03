#include "../include/AbilitySet.h"

AbilitySet::AbilitySet()
{
    std::cout << "CONSTRUCTION FOR NEW ABILITY SET\n";
}

AbilitySet::AbilitySet(const AbilitySet& src)
{
    std::cout << "COPY CONSTRUCTION FOR NEW ABILITY SET\n";
}

AbilitySet::iterator AbilitySet::begin()
{
    return this -> knownAbilities.begin();
}

AbilitySet::iterator AbilitySet::end()
{
    return this -> knownAbilities.end();
}

AbilitySet::const_iterator AbilitySet::begin() const
{
    return this -> knownAbilities.begin();
}

AbilitySet::const_iterator AbilitySet::end() const
{
    return this -> knownAbilities.end();
}

void AbilitySet::add(std::unique_ptr<Ability> to_add)
{
    this -> knownAbilities.emplace_back(std::move(to_add));
}


void AbilitySet::display(std::ostream& outs) const
{
    if(this -> knownAbilities.empty())
    {
        std::cout << "No abilities known!\n";
        return;
    }

    for(const std::unique_ptr<Ability>& ptrToAbility : knownAbilities)
    {
        std::cout << *ptrToAbility << '\n';
    }
}