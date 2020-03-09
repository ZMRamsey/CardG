#include "UserInterface.h"
#include "CardBox.h"
#include "Hand.h"
#include "Card.h"
#include <stdlib.h>

int main()
{
	UserInterface gui;
	char resp;

	gui.titleScreen();
	gui.mainMenu();

	while (true)
	{
		resp = gui.getInput();
		if ((resp == 'p') || (resp == 'q')){ break; }
	}
	if (resp == 'q')
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		//play the game
	}

	//gui.displayBoard();

	//gui.clearScreen();

	//gui.displayBoard();
}
