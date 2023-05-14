#include <iostream>
#include <fstream>

#include "../../include/Entity/Enemy.h"
#include "../../include/Entity/Character.h"
#include "../../include/Entity/EntityGenerator.h"
#include "../../include/Battle/Battle.h"
#include "../../include/Battle/BattleManager.h"

void Menu();
void Start(Character&& player1);

int main()
{
	//Menu();
	return 0;
}

void Menu()
{	
	int userChoice = 0;

	std::cout << "Welcome to Dom's Turn Based Combat Game.\n"
			  << "would you like to load a character or start a new one?\n"
			  << "New Character...\t1\n"
			  << "Load Character...\t2\n";

	std::cin >> userChoice;

	switch(userChoice)
	{	
		case 1:
			Start(EntityGenerator::CreateNewCharacter());
			break;
		case 2:
			Start(EntityGenerator::LoadCharacter(CHARACTER_SAVE_PATH));
			break;
		default:
			break;
	}
	
}

void Start(Character&& player1)
{
	system("clear");

}

