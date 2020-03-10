#pragma once

using namespace std;

class UserInterface
{
	public:
		void updateGUI(char output);
		char getInput();
		void displayBoard(string playerName, string enemyName, int power1, int power2, Card[5], Card[5], Hand enemyHand, Hand playerHand);
		void clearScreen();
		void titleScreen();
		void mainMenu();
		string bracketCheck(Card card, bool isTop);
};

