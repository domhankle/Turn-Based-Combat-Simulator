#include <iostream>
#include <fstream>

#include "../../include/Entity/Enemy.h"
#include "../../include/Entity/Character.h"
#include "../../include/Entity/EntityGenerator.h"
#include "../../include/Battle/Battle.h"
#include "../../include/Battle/BattleManager.h"
#include "../../include/Battle/BattleGenerator.h"

void Menu();
void Start(Character&& player1);

int main()
{

	Character char1("Dom", 100, 1);
	char1.LearnAbility(OffensiveAbility("Punch", 5));
	char1.LearnAbility(DefensiveAbility("Block", 0));
	char1.LearnAbility(DefensiveAbility("Wall", 45));
	char1.LearnAbility(OffensiveAbility("Thunder Strike", 55));


	BattleManager bm(BattleGenerator::GenerateBattle(char1, EntityGenerator::GenerateEnemy(1)));
	bm.BattleLoop();

	

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

