#include "Card.h"
#include "Hand.h"
#include <string>

#pragma once

#include <string>
#include <iostream>

using namespace std;

class UserInterface
{
	public:
		void updateGUI(char output);
		char getInput();
		string getName();
		void displayBoard(string playerName, string enemyName, int power1, int power2, Card[5], Card[5], Hand enemyHand, Hand playerHand);
		void clearScreen();
		void titleScreen();
		void mainMenu();
		void cardSelect(Card, Card);
		void showHand();
		void stealRemoveSelect(bool stealNotRemove, bool fromHand, Card[5], Card[5], Hand hand);
		string bracketCheck(Card* card, bool isTop);
		string fixLength(string starter, int length);
		void victoryScreen(bool playerWin, int power1, int power2);
		void chooseAI();
		int viewHand(Hand playerHand, int cardNum, int power);
		string name;
		void print(string str, bool check);
};

