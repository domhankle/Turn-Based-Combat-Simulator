#include <iostream>
#include "../include/AbilitySet.h"
#include "../include/OffensiveAbility.h"

int main()
{

	AbilitySet setOfAbilities;

	std::unique_ptr<Ability> ptr1(new OffensiveAbility("BOLT", 35.5));

	setOfAbilities.add(std::unique_ptr<Ability>(new OffensiveAbility("BOLT", 35.5)));

	std::cout << setOfAbilities;
	return 0;
}


