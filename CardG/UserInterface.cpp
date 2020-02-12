#include "UserInterface.h"
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

void UserInterface::displayBoard()
{

}
