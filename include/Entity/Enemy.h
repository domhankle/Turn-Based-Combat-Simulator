#ifndef ENEMY_H
#define ENEMY_H


#include "Entity.h"


/**
 * @brief This class represents the characteristics and functions of an Enemy which
 *        derives from the abstract class Entity.
 * 
 */
class Enemy : public Entity
{

    private:

        float damage;

    public:

        /**
         * @brief Default Constructor not available for use.
         * 
         */
        Enemy() = delete;

        /**
         * @brief Construct a new Enemy object.
         * 
         * @param aName The name of this Enemy object will have.
         * @param numHealthPoints The health of this Enemy object.
         * @param damageAmount The max damage this Enemy can do.
         */
        Enemy(std::string aName, int numHealthPoints, float damageAmount);

        /**
         * @brief Construct a new Enemy object as a copy of an existing Enemy object.
         * 
         * @param src The existing Enemy object to copy.
         */
        Enemy(const Enemy& src);
        
        /**
         * @brief Destructor for an Enemy object.
         * 
         */
        ~Enemy() override;

        /**
         * @brief Output a string representation of the Enemy object.
         * 
         * @param outs The output stream to send the string representation of the Enemy
         *             object to.
         */
        void Display(std::ostream& outs) const override;

        void Extract(std::istream& ins) override;

        /**
         * @brief Set the max damage that the enemy can do.
         * 
         * @param damageAmount The max amount of damage this enemy can do.
         */
        void SetDamage(float damageAmount);

        /**
         * @brief Get the max damage an Enemy can do.
         * 
         * @return The max damage an enemy can do.
         */
        float GetDamage() const;



};

#endif