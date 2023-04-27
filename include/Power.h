#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <string>


class Power
{

	public:

		Power() = delete;
		~Power() = default;
		Power(std::string aName, bool aBool);
		
		virtual void LevelUp() = 0;

		void SetName(std::string aName);
		std::string GetName() const;
		

	private:

		bool isOffensive;

	protected:

		std::string name;		

	
};

#endif
