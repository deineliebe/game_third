#include <iostream>
#include <stdio.h>
#include "Field.h"
#include "Unit.h"
#include "Facade.h"

bool ClientCode(BaseSubsystem baseSubsystem, UnitSubsystem unitSubsystem, Facade facade, Game &game)
{
	int check = 1;
	while (check)
	{
		check = facade.chooseFunction(baseSubsystem, unitSubsystem, game);
		std::cout << '\n';
		if (game.ifExist()) game.show();
		std::cout << '\n';
	}
	return 1;
}

int main()
{
	BaseSubsystem baseSubsystem;
	UnitSubsystem unitSubsystem;
	Facade facade;
	Game game;
	if (!ClientCode(baseSubsystem, unitSubsystem, facade, game)) throw "Error\n";
	if (game.ifExist()) game.~Game();
}