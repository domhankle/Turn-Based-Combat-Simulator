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
 * @brief This class encapsulates the logic for creating a new Entity. Whether it be loading
 *        a saved character file or generating a random enemy.
 * 
 */
class EntityGenerator
{

    public:

        /**
         * @brief Constructor not available for use. This class should not be instantiated.
         * 
         */
        EntityGenerator() = delete;
        
        /**
         * @brief Prompt the user for creation of a new Character object and it's configuration data.
         * 
         * @return The default new character object.
         */
        static Character CreateNewCharacter();

        /**
         * @brief Load a character from a saved character file.
         * 
         * @param saveFile The path location of the character save file which holds configuration data.
         * @return If the save file exists, return the saved character.
         *         If the save file does not exists, return a default character object with the name "Default".
         */
        static Character LoadCharacter(std::string saveFile);

        /**
         * @brief Generate a random enemy based on stage input.
         * 
         * @param stage If stage = 1, use ENEMIES_STAGE_1_PATH
         *              If stage = 2, use ENEMIES_STAGE_2_PATH
         *              If stage = 3, use ENEMIES_STAGE_3_PATH
         * 
         * @return Return an enemy from the associated stage using randomized generator.
         */
        static Enemy GenerateEnemy(int stage);

};

#endif