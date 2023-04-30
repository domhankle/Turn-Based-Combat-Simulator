#include <iostream>
#include "../include/Character.h"
#include "../include/Enemy.h"
int main()
{
	Character char1("JoeMama");
	Enemy ene1("DEMON", 50000);

	std::cout << char1 << '\n' << ene1;
	return 0;
}


