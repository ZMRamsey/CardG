#include "UserInterface.h"
#include "Card.h"
#include "Hand.h"
#include <string>
#include <iostream>

using namespace std;

void UserInterface::updateGUI(char output)
{
	cout << "\n" << output;
}

char UserInterface::getInput()
{
	char resp;
	cout << "\n>";
	cin >> resp;
	return resp;
}

void UserInterface::displayBoard(string playerName, string enemyName, int power1, int power2, Card board1[5], Card board2[5], Hand hand1, Hand hand2)
{
	//clear screen
	clearScreen();

	//fix name

	while (playerName.length < 13)
	{
		playerName = playerName + " ";
	}
	//names are 13 characters long

	//TODO: Make face react to difference in power levels
	
	//Enemy avatar, must be 5 characters
	string face = " OwO ";

	string cardsB[10];
	for (int i = 0; i < 10; i++)
	{
		string testString;
		if (i < 5)
		{
			if (board1[i].checkIfNull)
			{
				testString = "  ";
			}
			else
			{
				testString = board1[i].getCurrentDisplayName();
			}
		}
		else
		{
			if (board2[i - 5].checkIfNull)
			{
				testString = "  ";
			}
			else
			{
				testString = board2[i - 5].getCurrentDisplayName();
			}
		}

		cardsB[i] = testString;
	}
	
	//Cards in hand, must be 2 characters/2 with brackets
	string hand1A = bracketCheck(hand2.getOne, true);
	string hand1B = bracketCheck(hand2.getOne, false);
	string hand2A = bracketCheck(hand2.getTwo, true);
	string hand2B = bracketCheck(hand2.getTwo, false);
	string hand3A = bracketCheck(hand2.getThree, true);
	string hand3B = bracketCheck(hand2.getThree, false);
	string hand4A = bracketCheck(hand2.getFour, true);
	string hand4B = bracketCheck(hand2.getFour, false);
	string hand5A = bracketCheck(hand2.getFive, true);
	string hand5B = bracketCheck(hand2.getFive, false);




	//display board
	cout << " ______________________________________________________ " << endl;
	cout << "| " << enemyName << " /                                       |" << endl;
	cout << "|_____________/                   " << face << "                |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|      _________________________________   _____       |" << endl;
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << endl;
	cout << "|     |  |" << cardsB[0] << "|  |" << cardsB[1] << "|  |" << cardsB[2] << "|  |" << cardsB[3] << "|  |" << cardsB[4] << "|  |  |-----|      |" << endl;
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  " << power1 << "  |      |" << endl;
	cout << "|     |________________________________|  |_____|      |" << endl;
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << endl;
	cout << "|     |  |" << cardsB[5] << "|  |" << cardsB[6] << "|  |" << cardsB[7] << "|  |" << cardsB[8] << "|  |" << cardsB[9] << "|  |  |-----|      |" << endl;
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  " << power2 << "  |      |" << endl;
	cout << "|     |________________________________|  |_____|      |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|  ____     ____     ____     ____     ____            |" << endl;
	cout << "| |" << hand1A << "|   |" << hand2A << "|   |" << hand3A << "|   |" << hand4A << "|   |" << hand5A << "|           |" << endl;
	cout << "| |" << hand1B << "|   |" << hand2B << "|   |" << hand3B << "|   |" << hand4B << "|   |" << hand5B << "|           |" << endl;
	cout << "| |____|   |____|   |____|   |____|   |____|           |" << endl;
	cout << "|  [1]      [2]      [3]      [4]      [5]             |" << endl;
	cout << "|______________________________________________________|" << endl;
	cout << " [q] Quit  [h] Hand  [b] Board    \\ " << playerName << "     |" << endl;
	cout << "                                   \\___________________|" << endl;

}

void UserInterface::clearScreen()
{
	for (int i = 0; i < 25; i++)
	{
		cout << "\n";
	}
}

void UserInterface::titleScreen()
{
	cout << "_________                  .___          ________  " << endl;
	cout << "\\_   ___ \\_____ _______  __| _/         /  _____/  " << endl;
	cout << "/    \\  \\/\\__  \\\\_  __ \\/ __ |  ______ /   \\  ___  " << endl;
	cout << "\\     \\____/ __ \\|  | \\/ /_/ | /_____/ \\    \\_\\  \\ " << endl;
	cout << " \\______  (____  /__|  \\____ |          \\______  / " << endl;
	cout << "        \\/     \\/           \\/                 \\/ " << endl;
	cout << "\n" << "             Zoey Ramsey - 2020" << "\n \n";
}

void UserInterface::mainMenu()
{
	cout << "             [p] Play  [q] Quit" << endl;
}

string UserInterface::bracketCheck(Card card, bool isTop)
{
	string str;
	bool addBrackets;
	if (isTop)
	{
		str = card.getDisplayName1();
		if (card.getTopHighlight)
		{
			addBrackets = true;
		}
		else
		{
			addBrackets = false;
		}
	}
	else
	{
		str = card.getDisplayName2();
		if (!card.getTopHighlight)
		{
			addBrackets = true;
		}
		else
		{
			addBrackets = false;
		}
	}

	if (addBrackets)
	{
		str = "(" + str + ")";
	}
	else
	{
		str = " " + str + " ";
	}
}

