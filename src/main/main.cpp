#include <iostream>

#include "../../include/Ability/AbilitySet.h"

int main()
{
	
	AbilitySet set;

	set.add(std::unique_ptr<DefensiveAbility>(new DefensiveAbility("WALL", 10)));
	set.add(std::unique_ptr<OffensiveAbility>(new OffensiveAbility("BOLT", 35.5)));

	AbilitySet set2(set);

	AbilitySet set3;

	set3 = set2;
	std::cout << set << set2 << set3;

	return 0;
}


