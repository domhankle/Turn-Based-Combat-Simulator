#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

/**
 * @brief A class that represents the user that will attack the enemies throughout
 * this application. It inherits from the Entity class.
 *
 * 
 */
class Character
{
    private:

        std::string name;
        int health;
        int level;

    public:


        /**
         * @brief Default Constructor is not available for use.
         * 
         */
        Character() = delete;

        /**
         * @brief Construct a new Character object
         * 
         * @param name The character's name.
         */
        Character(std::string name);

        /**
         * @brief Destroy a Character object.
         * 
         * 
         */
        ~Character();

        /**
         * @brief Construct a copy of a current existing Character object.
         * 
         * @param src The existing Character object to copy.
         */
        Character(const Character& src);

        

        
};

#endif