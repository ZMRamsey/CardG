#include "UserInterface.h"
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
	while (true)
	{
		cout << "\n>";
		cin >> resp;
		return resp;
	}
}

string UserInterface::getName()
{
	string name;

	cout << "What is your name?" << endl;

	while (true) {
		cout << "\n>";
		cin >> name;
		if (name.length() <= 13) { return name; }
		else
		{
			cout << "Name is too long";
		}
	}
}

void UserInterface::displayBoard(string enemyName, string playerName, int power1, int power2, Card board1[5], Card board2[5], Hand hand1, Hand hand2)
{
	//clear screen
	clearScreen();

	//fix name
	while (playerName.length() <= 13)
	{
		playerName = playerName + " ";
	}
	while (enemyName.length() <= 13)
	{
		enemyName = enemyName + " ";
	}

	//names are 13 characters long
	
	//Enemy avatar, must be 5 characters
	string face;
	
	if (power1 > power2)
	{
		face = " UwU ";
	}
	else
	{
		face = " OwO ";
	}

	string cardsB[10];
	for (int i = 0; i < 10; i++)
	{
		string testString;
		if (i < 5)
		{
			if (board1[i].checkIfNull())
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
			if (board2[i - 5].checkIfNull())
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
	//Card testCard = Card();
	//testCard = *hand2.getOne();

	string blank = "    ";
	string hand1A = blank;
	string hand1B = blank;
	string hand2A = blank;
	string hand2B = blank;
	string hand3A = blank;
	string hand3B = blank;
	string hand4A = blank;
	string hand4B = blank;
	string hand5A = blank;
	string hand5B = blank;


	if (!hand2.getOne()->checkIfNull())
	{
		hand1A = bracketCheck(hand2.getOne(), true);
		hand1B = bracketCheck(hand2.getOne(), false);
	}

	if (!hand2.getTwo()->checkIfNull())
	{
		hand2A = bracketCheck(hand2.getTwo(), true);
		hand2B = bracketCheck(hand2.getTwo(), false);
	}

	if (!hand2.getThree()->checkIfNull())
	{
		hand3A = bracketCheck(hand2.getThree(), true);
		hand3B = bracketCheck(hand2.getThree(), false);
	}

	if (!hand2.getFour()->checkIfNull())
	{
		hand4A = bracketCheck(hand2.getFour(), true);
		hand4B = bracketCheck(hand2.getFour(), false);
	}

	if (!hand2.getFive()->checkIfNull())
	{
		hand5A = bracketCheck(hand2.getFive(), true);
		hand5B = bracketCheck(hand2.getFive(), false);
	}


	//display board
	cout << " ______________________________________________________ " << endl;
	cout << "|" << enemyName << "/                                       |" << endl;
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
	for (int i = 0; i < 18; i++)
	{
		cout << "\n";
	}

	//system("CLS");
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

void UserInterface::cardSelect(Card card1, Card card2)
{
	clearScreen();

	//name of cards, must be 17 chars long
	string name1 = card1.name;
	name1 = fixLength(name1, 17);

	string name2 = card2.name;
	name2 = fixLength(name2, 17);

	//effect names, must also be 17 chars long
	string effect11 = card1.type1->name;
	effect11 = fixLength(effect11, 17);

	string effect12 = card1.type2->name;
	effect12 = fixLength(effect12, 17);

	string effect21 = card2.type1->name;
	effect21 = fixLength(effect21, 17);

	string effect22 = card2.type2->name;
	effect22 = fixLength(effect22, 17);

	//pivot values
	int pivot1 = card1.pivot;
	int pivot2 = card2.pivot;

	cout << "  ___________________          ___________________  " << endl;
	cout << " | " << name1 << " |        | " << name2 << " | " << endl;
	cout << " |///////////////////|        |///////////////////| " << endl;
	cout << " | " << effect11 << " |        | " << effect21 << " | " << endl;
	cout << " |                   |  ----  |                   | " << endl;
	cout << " |-------------------|  =OR=  |-------------------| " << endl;
	cout << " | " << effect12 << " |  ----  | " << effect22 << " | " << endl;
	cout << " |         __________|        |         __________| " << endl;
	cout << " |        / PIVOT: " << pivot1 << " |        |        / PIVOT: " << pivot2 << " | " << endl;
	cout << " |_______/___________|        |_______/___________| " << endl;
	cout << "                                                    " << endl;
	cout << "          [1]                          [2]          " << endl;

}

void UserInterface::showHand()
{
	//Show full hand when player asks
}

void UserInterface::stealRemoveSelect(bool stealNotRemove, bool fromHand, Card board1[5], Card board2[5], Hand hand)
{
	string cardsB[10];
	for (int i = 0; i < 10; i++)
	{
		string testString;
		if (i < 5)
		{
			if (board1[i].checkIfNull())
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
			if (board2[i - 5].checkIfNull())
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


	if (stealNotRemove)
	{
		cout << " ================ STEAL ================ " << endl;
	}
	else
	{
		cout << " =============== REMOVE ================ " << endl;
	}

	if (fromHand)
	{
		string card1, card2, card3, card4, card5;
		if (hand.getOne()->checkIfNull()) { card1 = " "; }
		else { card1 = "?" ; }

		if (hand.getTwo()->checkIfNull()) { card2 = " "; }
		else { card2 = "?"; }
		
		if (hand.getThree()->checkIfNull()) { card3 = " "; }
		else { card3 = "?"; }
		
		if (hand.getFour()->checkIfNull()) { card4 = " "; }
		else { card4 = "?"; }

		if (hand.getFive()->checkIfNull()) { card5 = " "; }
		else { card5 = "?"; }


		cout << "     ___    ___    ___    ___    ___     " << endl;
		cout << "    |   |  |   |  |   |  |   |  |   |    " << endl;
		cout << "    | " << card1 << " |  | " << card2 << " |  | " << card3 << " |  | " << card4 << " |  | " << card5 << " |    " << endl;
		cout << "    |___|  |___|  |___|  |___|  |___|    " << endl;
		cout << "     [1]    [2]    [3]    [4]    [5]     " << endl;
	}
	else
	{
		if (stealNotRemove)
		{
			//cout << " ================ STEAL ================ " << endl;
			cout << "   .________________________________. " << endl;
			cout << "   |                                | " << endl;
			cout << "   |   [1]   [2]   [3]   [4]   [5]  | " << endl;
			cout << "   |   __    __    __    __    __   | " << endl;
			cout << "   |  |" << cardsB[0] << "|  |" << cardsB[1] << "|  |" << cardsB[2] << "|  |" << cardsB[3] << "|  |" << cardsB[4] << "|  | " << endl;
			cout << "   |  |__|  |__|  |__|  |__|  |__|  | " << endl;
			cout << "   |________________________________| " << endl;
		}
		else
		{
			//cout << " =============== REMOVE ================ " << endl;
			cout << "   .________________________________. " << endl;
			cout << "   |                                | " << endl;
			cout << "   |   [1]   [2]   [3]   [4]   [5]  | " << endl;
			cout << "   |   __    __    __    __    __   | " << endl;
			cout << "   |  |" << cardsB[0] << "|  |" << cardsB[1] << "|  |" << cardsB[2] << "|  |" << cardsB[3] << "|  |" << cardsB[4] << "|  | " << endl;
			cout << "   |  |__|  |__|  |__|  |__|  |__|  | " << endl;
			cout << "   |   __    __    __    __    __   | " << endl;
			cout << "   |  |" << cardsB[5] << "|  |" << cardsB[6] << "|  |" << cardsB[7] << "|  |" << cardsB[8] << "|  |" << cardsB[9] << "|  | " << endl;
			cout << "   |  |__|  |__|  |__|  |__|  |__|  | " << endl;
			cout << "   |                                | " << endl;
			cout << "   |  [6]   [7]   [8]   [9]   [0]   | " << endl;
			cout << "   |________________________________| " << endl;
		}
	}
}

string UserInterface::bracketCheck(Card* testCard, bool isTop)
{
	string testString = "    ";
	bool addBrackets;
	if (isTop)
	{
		testString = testCard->getDisplayName1();
		if (testCard->getTopHighlight())
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
		testString = testCard->getDisplayName2();
		if (!testCard->getTopHighlight())
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
		testString = "(" + testString + ")";
	}
	else
	{
		testString = " " + testString + " ";
	}

	return testString;
}

string UserInterface::fixLength(string starter, int length)
{
	bool centralise = true;
	while (starter.length() < length)
	{
		if (centralise)
		{
			starter = starter + " ";
			centralise = false;
		}
		else
		{
			starter = " " + starter;
			centralise = true;
		}
	}
	
	return starter;
}

