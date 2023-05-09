#include "../../include/Ability/AbilitySet.h"

AbilitySet::AbilitySet()
{
}

AbilitySet::AbilitySet(const AbilitySet& src)
{
    for(const std::unique_ptr<Ability>& abilityPtr : src)
    {
        if(abilityPtr -> IsOffensiveAbiility())
        {
            this -> add(std::make_unique<OffensiveAbility>(dynamic_cast<OffensiveAbility&>(*abilityPtr)));
        }
        else if(!(abilityPtr -> IsOffensiveAbiility()))
        {
            this -> add(std::make_unique<DefensiveAbility>(dynamic_cast<DefensiveAbility&>(*abilityPtr)));
        }
        else
        {
            std::cerr << "Error in copying Ability Set. This type of Ability object has not had implementation\n"
                      << "to the copy constructor yet for the AbilitySet class.";
            system("EXIT_FAILURE");
        }
    }
}

AbilitySet::AbilitySet(AbilitySet&& src)
{
   this -> knownAbilities = std::move(src.knownAbilities);
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
        outs << "No abilities known!\n";
        return;
    }

    for(const std::unique_ptr<Ability>& ptrToAbility : *this)
    {
        outs << *ptrToAbility << '\n';
    }
}

void AbilitySet::extract(std::istream& ins)
{
    std::string garbage;
    
    OffensiveAbility OAbility;
    DefensiveAbility DAbility;

    ins >> garbage;

    while(ins)
    {
        garbage = "";
        ins >> std::ws >> garbage;
        if(garbage == "(OFFENSIVE)")
        {
            ins >> OAbility;
            this -> add(std::make_unique<OffensiveAbility>(std::move(OAbility)));
        }
        else if(garbage == "(DEFENSIVE)")
        {
            ins >> DAbility;
            this -> add(std::make_unique<DefensiveAbility>(std::move(DAbility)));
        }

    }


}

AbilitySet& AbilitySet::operator=(AbilitySet rhs)
{
    swap(*this, rhs);

    return *this;
}

void swap(AbilitySet& lhs, AbilitySet& rhs)
{
    std::swap(lhs.knownAbilities, rhs.knownAbilities);
}