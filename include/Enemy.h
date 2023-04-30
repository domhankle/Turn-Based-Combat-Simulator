#include "Entity.h"

/**
 * @brief This class represents the characteristics and functions of an Enemy which
 *        derives from the abstract class Entity.
 * 
 */
class Enemy : Entity
{

    private:

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
         */
        Enemy(std::string aName, int numHealthPoints);

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
        ~Enemy();

        /**
         * @brief Output a string representation of the Enemy object.
         * 
         * @param outs The output stream to send the string representation of the Enemy
         *             object to.
         */
        void Display(std::ostream& outs) const override;

};

/**
 * @brief Overload of the stream insertion operator for the Enemy class.
 * 
 * @param outs The output stream that the string 
 * @param src 
 * @return std::ostream& 
 */
inline
std::ostream& operator<<(std::ostream& outs, const Enemy& src) 
{
    src.Display(outs);

    return outs;
}