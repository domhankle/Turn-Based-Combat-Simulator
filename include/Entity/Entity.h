#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief The abstract base class that defines base level enemy and character
 * behavior.
 * 
 */
class Entity
{
    private:

    protected:

        std::string name;
        int health;
        

    public:

        /**
         * @brief Constructor set to default use.
         * 
         */
        Entity() = default;

        /**
         * @brief Construct a new Entity object with a custom name and health amount.
         * 
         * @param aName Name of the new entity object.
         * @param healthAmount Base health for the new entity object.
         */
        Entity(std::string aName, int healthAmount);

        /**
         * @brief Destructor has default use.
         * 
         */
        virtual ~Entity() = default;

        /**
         * @brief Get the name of the Entity.
         * 
         * @return name of the enemy as a std::string.
         */
        std::string GetName() const;

        /**
         * @brief Set the name of the Entity.
         * 
         * @param aName The std::string value to set as the Entities name.
         */
        void SetName(std::string aName);

        /**
         * @brief Get the current amount of health of the Entity.
         * 
         * @return the current amount of health of the Entity as an int.
         */
        int GetHealth() const;

        /**
         * @brief Set the health of the Entity.
         * 
         * @param numHealthPoints The int value to set as the Entities current health.
         */
        void SetHealth(int numHealthPoints);

        /**
         * @brief This function outputs the string value of an Entity
         *        object.
         * 
         * @param outs The output stream to send the Entity string representation to.
         */
        virtual void Display(std::ostream& outs) const;

        /**
         * @brief This function extracts value from an input stream and configures
         *        the values to an Entity object.
         * 
         * @param ins The input stream contatining the values.
         */
        virtual void Extract(std::istream& ins);


};

inline
std::ostream& operator<<(std::ostream& outs, const Entity& src)
{
    src.Display(outs);
    return outs;
}

inline
std::istream& operator>>(std::istream& ins, Entity& src)
{
    src.Extract(ins);
    return ins;
}

#endif