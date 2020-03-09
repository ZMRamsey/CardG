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

void UserInterface::displayBoard(string name, int power1, int power2, Card board1[5], Card board2[5], Hand hand1, Hand hand2)
{
	//clear screen
	clearScreen();

	//fix name

	while (name.length < 13)
	{
		name = name + " ";
	}
	//names are 13 characters long

	//Enemy avatar, must be 5 characters
	string face = " OwO ";

	int power1 = 3;
	int power2 = 5;

	string cardsB[10];
	for (int i = 0; i < 10; i++)
	{
		string testString;
		if (i < 5)
		{
			testString = board1[i].getCurrentDisplayName();
		}
		else
		{
			testString = board2[i - 5].getCurrentDisplayName();
		}

		if (testString == "PLACEHOLDER")
		{
			testString = "  ";
		}

		cardsB[i] = testString;
	}
	
	//Cards in hand, must be 2 characters/2 with brackets
	string hand1A = bracketCheck(hand1.getOne, true);
	string hand1B = bracketCheck(hand1.getOne, false);
	string hand2A = bracketCheck(hand1.getTwo, true);
	string hand2B = bracketCheck(hand1.getTwo, false);
	string hand3A = bracketCheck(hand1.getThree, true);
	string hand3B = bracketCheck(hand1.getThree, false);
	string hand4A = bracketCheck(hand1.getFour, true);
	string hand4B = bracketCheck(hand1.getFour, false);
	string hand5A = bracketCheck(hand1.getFive, true);
	string hand5B = bracketCheck(hand1.getFive, false);




	//display board
	cout << " ______________________________________________________ " << "\n";
	cout << "| " << name << " /                                       |" << "\n";
	cout << "|_____________/                   " << face << "                |" << "\n";
	cout << "|                                                      |" << "\n";
	cout << "|      _________________________________   _____       |" << "\n";
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << "\n";
	cout << "|     |  |" << cardsB[0] << "|  |" << cardsB[1] << "|  |" << cardsB[2] << "|  |" << cardsB[3] << "|  |" << cardsB[4] << "|  |  |-----|      |" << "\n";
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  " << power1 << "  |      |" << "\n";
	cout << "|     |________________________________|  |_____|      |" << "\n";
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << "\n";
	cout << "|     |  |" << cardsB[5] << "|  |" << cardsB[6] << "|  |" << cardsB[7] << "|  |" << cardsB[8] << "|  |" << cardsB[9] << "|  |  |-----|      |" << "\n";
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  " << power2 << "  |      |" << "\n";
	cout << "|     |________________________________|  |_____|      |" << "\n";
	cout << "|                                                      |" << "\n";
	cout << "|  ____     ____     ____     ____     ____            |" << "\n";
	cout << "| |" << hand1A << "|   |" << hand2A << "|   |" << hand3A << "|   |" << hand4A << "|   |" << hand5A << "|           |" << "\n";
	cout << "| |" << hand1B << "|   |" << hand2B << "|   |" << hand3B << "|   |" << hand4B << "|   |" << hand5B << "|           |" << "\n";
	cout << "| |____|   |____|   |____|   |____|   |____|           |" << "\n";
	cout << "|  [1]      [2]      [3]      [4]      [5]             |" << "\n";
	cout << "|______________________________________________________|" << "\n";
	cout << " [q] Quit  [h] Hand  [b] Board    \\ " << name << "     |" << "\n";
	cout << "                                   \\___________________|" << "\n";

}

void UserInterface::clearScreen()
{
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
	cout << "\n" << "\n";
}

void UserInterface::titleScreen()
{
	cout << "_________                  .___          ________  " << "\n";
	cout << "\\_   ___ \\_____ _______  __| _/         /  _____/  " << "\n";
	cout << "/    \\  \\/\\__  \\\\_  __ \\/ __ |  ______ /   \\  ___  " << "\n";
	cout << "\\     \\____/ __ \\|  | \\/ /_/ | /_____/ \\    \\_\\  \\ " << "\n";
	cout << " \\______  (____  /__|  \\____ |          \\______  / " << "\n";
	cout << "        \\/     \\/           \\/                 \\/ " << "\n";
	cout << "\n" << "             Zoey Ramsey - 2020" << "\n \n";
}

void UserInterface::mainMenu()
{
	cout << "             [p] Play  [q] Quit" << "\n";
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

