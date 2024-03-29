#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Entity.h"
#include "../Ability/AbilitySet.h"

const std::string CHARACTER_SAVE_PATH = "Game_Data/character_save.txt";

/**
 * @brief A class that represents the user that will attack the enemies throughout
 * this application. It inherits from the Entity class.
 */
class Character : public Entity
{
    public:

        using iterator = std::vector<Ability>::iterator;
        using const_iterator = std::vector<Ability>::const_iterator;

    private:
    
        int level;
        AbilitySet abilities_known;
        

    public:


        /**
         * @brief Default Constructor is not available for use.
         * 
         */
        Character() = delete;

        /**
         * @brief Construct a new Character object with just a name value.
         * 
         * @param name The name of the new character object.
         */
        Character(std::string name);

        /**
         * @brief Construct a new Character object
         * 
         * @param name The character's name.
         * @param health The character's health.
         * @param level The character's level.
         */
        Character(std::string name, int health, int level);

        /**
         * @brief Destroy a Character object.
         */
        ~Character() override;

        /**
         * @brief Construct a copy of a current existing Character object.
         * 
         * @param src The existing Character object to copy.
         */
        Character(const Character& src);

        /**
         * @brief Output a string representation of a Character.
         * 
         * @param outs The output stream to send the string representation of
         *             a Character object to.
         */
        void Display(std::ostream& outs) const override;

        /**
         * @brief This function extracts values from an input stream and configures them
         *        properly to a Character object.
         * 
         * @param ins The input stream containing the values.
         */
        void Extract(std::istream& ins) override;
        
        /**
         * @brief Get the the level of a the Character Object.
         * 
         * @return The current level of the Character object.
         */
        int GetLevel() const;

        /**
         * @brief Set the current level of a Character object.
         * 
         * @param aLevel The level to set the Character objects level to.
         * 
         */
        void SetLevel(int aLevel);

        /**
         * @brief Add an ability to the characters ability set. Wrapper to the add function
         *        for the AbilitySet class.
         * 
         * @param src The ability to add to the characters ability set.
         */
        void LearnAbility(Ability&& src);

        /**
         * @brief Get the abilities known by this character.
         * 
         * @return the AbilitySet object that holds all of the abilities known by this character. 
         */
        AbilitySet GetKnownAbilities() const;
        
};

#endif