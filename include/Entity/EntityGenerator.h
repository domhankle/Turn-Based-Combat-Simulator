#ifndef ENTITY_GENERATOR_H
#define ENTITY_GENERATOR_H

#include "Entity.h"
#include "Enemy.h"
#include "Character.h"
#include <fstream>


const std::string ENEMIES_STAGE_1_PATH = "Game_Data/known_enemies_1.txt";
const std::string ENEMIES_STAGE_2_PATH = "Game_Data/known_enemies_2.txt";
const std::string ENEMIES_STAGE_3_PATH = "Game_Data/known_enemies_3.txt";

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
class EntityGenerator
{

    private:

    public:

        EntityGenerator() = delete;
        
        static Character CreateNewCharacter();
        static Character LoadCharacter(std::string saveFile);

        static Enemy GenerateEnemy(int stage);

};

#endif