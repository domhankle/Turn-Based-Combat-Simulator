#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include <string>

/**
 * @brief An abstract base class that all Character and Enemy abilities
 * derive from.
 */
class Ability
{

	private:

		bool isOffensive;

	protected:

		std::string name;

	public:
		
		/**
		 * @brief Constructor set to default use.
		 * 
		 */
		Ability() = default;

		/**
		 * @brief Copy Constructor set to default use.
		 * 
		 * @param src The source to copy.
		 */
		Ability(const Ability& src) = default;

		/**
		 * @brief Destructor is set to default use.
		 * 
		 */
		virtual ~Ability() = default;
		
		/**
		 * @brief Pure Virtual Function - Each type of ability will have the opportunity
		 * 		  to level up and increase it's abilities stats occasionally.
		 * 
		 */
		virtual void LevelUp() = 0;

		/**
		 * @brief Create a string representation of the Ability.
		 * 
		 * @param outs The output stream that the string representation will be sent to.
		 */
		virtual void display(std::ostream& outs) const;

		/**
		 * @brief Set the name of this ability.
		 * 
		 * @param aName The std::string value to set as this abilities name.
		 */
		void SetName(std::string aName);

		/**
		 * @brief Get the name of the ability.
		 * 
		 * @return std::string 
		 */
		std::string GetName() const;

		/**
		 * @brief Set the type of ability this is. (Offensive/Defensive)
		 * 
		 * @param offensiveType True = offensive ability. False = defensive ability.
		 */
		void SetType(bool offensiveType);

		/**
		 * @brief Get the typing of this ability. (Offensive/Defensive)
		 * 
		 * @return True if ability is offensive.
		 * @return False if ability is defensive.
		 */
		bool IsOffensiveAbiility() const;		

};

/**
 * @brief Stream insertion operator for Ability objects.
 * 
 * @param outs The output stream to send the string representation of the Ability to.
 * @param src The Ability object to retrieve a string representation of.
 * 
 * @return The output stream that contains the string representation of the Ability object.
 */
inline
std::ostream& operator<<(std::ostream& outs, const Ability& src)
{
	src.display(outs);
	return outs;
}

#endif
