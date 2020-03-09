#pragma once

using namespace std;

class UserInterface
{
	public:
		void updateGUI(char output);
		char getInput();
		void displayBoard(string, int, int, Card[5], Card[5], Hand, Hand);
		void clearScreen();
		void titleScreen();
		void mainMenu();
		string bracketCheck(Card card, bool);
};

