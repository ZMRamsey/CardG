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

void UserInterface::displayBoard(string playerName, string enemyName, int power1, int power2, Card*[] board1, Card*[] board2, Hand hand1, Hand hand2)
{
	//clear screen
	clearScreen();

	//fix name
	string name = "Zoey         ";
	//names are 13 characters long


	//display board
	cout << " ______________________________________________________ " << "\n";
	cout << "|"<< name << " /                   _ _                 |" << "\n";
	cout << "|_____________/                   ('_')                |" << "\n";
	cout << "|                                                      |" << "\n";
	cout << "|      _________________________________   _____       |" << "\n";
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << "\n";
	cout << "|     |  |  |  |  |  |  |  |-2|  |  |  |  |-----|      |" << "\n";
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  0  |      |" << "\n";
	cout << "|     |________________________________|  |_____|      |" << "\n";
	cout << "|     |   __    __    __    __    __   |  |POWER|      |" << "\n";
	cout << "|     |  |  |  |  |  |  |  |+2|  |+1|  |  |-----|      |" << "\n";
	cout << "|     |  |__|  |__|  |__|  |__|  |__|  |  |  1  |      |" << "\n";
	cout << "|     |________________________________|  |_____|      |" << "\n";
	cout << "|                                                      |" << "\n";
	cout << "|  ____     ____     ____     ____     ____            |" << "\n";
	cout << "| | R  |   |    |   | +2 |   |(+1)|   |    |           |" << "\n";
	cout << "| |    |   |    |   |(S) |   | -2 |   |    |           |" << "\n";
	cout << "| |____|   |____|   |____|   |____|   |____|           |" << "\n";
	cout << "|  [1]      [x]      [3]      [4]      [x]             |" << "\n";
	cout << "|______________________________________________________|" << "\n";
	cout << " [q] Quit  [h] Hand  [b] Board    |    Player turn     |" << "\n";
	cout << "                                  |____________________|" << "\n";

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

