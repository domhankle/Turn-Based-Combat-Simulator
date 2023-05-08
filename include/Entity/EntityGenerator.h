#ifndef ENTITY_GENERATOR_H
#define ENTITY_GENERATOR_H

#include "Entity.h"
#include "Enemy.h"
#include "Character.h"

/**
 * @brief NEEDS DOCUMENTATION
 * 
 */
class EntityGenerator
{
    public:

        EntityGenerator() = delete;
        
        static Character CreateNewCharacter();
        static Character LoadCharacter(std::string saveFile);

        static Enemy GenerateEnemy(Enemy&& enemy);
        static Enemy GenerateRandomEnemy(std::ifstream& knownEnemies);

};

#endif