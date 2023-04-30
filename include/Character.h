#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Entity.h"

/**
 * @brief A class that represents the user that will attack the enemies throughout
 * this application. It inherits from the Entity class.
 */
class Character : Entity
{
    private:
    
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

        /**
         * @brief Output a string representation of a Character.
         * 
         * @param outs The output stream to send the string representation of
         *             a Character object to.
         */
        void Display(std::ostream& outs) const override;

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
        
};


/**
 * @brief Overloading of the stream insertion operator for Character object.
 *        Simply a wrapper to it's display method.
 * 
 * @param outs The output stream to send the display method to.
 * @param src The character object to convert to a string representation.
 * 
 * @return The output stream filled with Character object string representation.
 */
inline
std::ostream& operator<<(std::ostream& outs, const Character& src)
{
    src.Display(outs);

    return outs;
}

#endif