#include "../../include/Entity/EntityGenerator.h"

Character EntityGenerator::CreateNewCharacter()
{
    std::string charName = "";

    std::cout << "What would you like to name your character?\n"
              << "Character Name: ";
    
    std::cin >> charName;

    Character newChar(charName);
    newChar.LearnAbility(OffensiveAbility("Punch", 5));
    newChar.LearnAbility(DefensiveAbility("Shield", 2.5));

    std::cout << '\n' << "Your character is created! Here's " << charName << "'s stats: \n"
              << newChar << '\n';
    
    return newChar;

}

Character EntityGenerator::LoadCharacter(std::string saveFile)
{
    std::cout << "Load Character has not been implemented yet.\n";

    return Character("Default");
}

Enemy EntityGenerator::GenerateEnemy(Enemy&& enemy)
{
    std::cout << "Generate Enemy has not been implemented yet.\n";

    return Enemy("Default", 100);
}

Enemy EntityGenerator::GenerateRandomEnemy(std::ifstream& knownEnemies)
{
    std::cout << "Generate Random Enemy has not been implemented yet.\n";

    return Enemy("Default", 100);
}
