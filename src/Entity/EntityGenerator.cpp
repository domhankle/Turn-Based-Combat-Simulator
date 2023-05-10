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
    Character to_return("Default");
    std::ifstream char_data(saveFile);

    if(!char_data)
    {
        std::cerr << "No save file found.\n";
    }

    char_data >> to_return;

    char_data.close();
    return to_return;
}

Enemy EntityGenerator::GenerateEnemy(Enemy&& enemy)
{
    std::cout << "Generate Enemy has not been implemented yet.\n";

    return Enemy("Default", 100, 10);
}


