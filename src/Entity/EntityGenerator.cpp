#include "../../include/Entity/EntityGenerator.h"
#include <random>

Enemy GetRandomEnemy(std::string file_path);
int GetRandomIndex(int maxIndex);

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

Enemy EntityGenerator::GenerateEnemy(int stage)
{
    switch(stage)
    {
        case 1:
            return GetRandomEnemy(ENEMIES_STAGE_1_PATH);
            
        default:
            break;
    }

    return Enemy("Default Enemy", 100, 10.5);
}

Enemy GetRandomEnemy(std::string file_path)
{
    std::ifstream enemy_file(file_path);
    std::vector<Enemy> enemies;

    while(enemy_file)
    {
        Enemy enemy("Default Enemy", 100, 10.5);
        enemy_file >> std::ws >> enemy >> std::ws;
        enemies.push_back(enemy);
    }


    enemy_file.close();

    return enemies.at(GetRandomIndex(enemies.size()-1));

};

int GetRandomIndex(int maxIndex)
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(0, maxIndex);

    return distribution(generator);
}