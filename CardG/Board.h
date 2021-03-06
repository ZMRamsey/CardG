#include "Card.h"
#include "Hand.h"
#include "CardType.h"
#include "CardBox.h"
#include "UserInterface.h"
#include "AIClass.h"
#include "AIHandler.h"
#include "Logger.h"
#include <stdlib.h>
#include <time.h>

#pragma once
class Board
{
	int power1;
	int power2;
	int marker;
	bool turn;

	int stealRemove;

	string p1Name;
	string p2Name;
	Card board1[5];
	Card board2[5];
	Card deck[22];
	Hand hand1;
	Hand hand2;
	UserInterface* gui;
	AIClass* ai;
	Logger* loggy;

public:
	Board();
	void startMatch();
	bool gameLoop();
	void displayBoard();
	void setPlayerPower(int power);
	void setEnemyPower(int power);
	bool playCard(int board, Card card);
	void drawCards();
	void shuffleCards();
	void playerStealOrRemove();
	void aiStealOrRemove();
	char displayHand();
	void logTurn(Card cardUsed, bool playerTurn);
};
