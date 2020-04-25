#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Hand.h"
#include "stdio.h"

using namespace std;

class Logger
{
private:
	int turnCount = 0;

public:
	Logger();
	void logTurn(Card board1[5], Card board2[5], Hand enemyHand, Hand playerHand, int power1, int power2, string playerName, string AI, Card cardPlayed, bool playerTurn);
	void newLog();

};

