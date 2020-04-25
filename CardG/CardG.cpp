#include "UserInterface.h"
#include "CardBox.h"
#include "Hand.h"
#include "Card.h"
#include "Board.h"
#include "Logger.h"
#include <stdlib.h>

int main()
{
	UserInterface gui;
	char resp;

	Board board;

	gui.titleScreen();
	gui.mainMenu();

	while (true)
	{
		resp = gui.getInput();
		if ((resp == 'p') || (resp == 'q'))
		{ 
			if (resp == 'q')
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				//play the game
				board.startMatch();

				//Return to title
				gui.titleScreen();
				gui.mainMenu();
			}
		}
	}
}
