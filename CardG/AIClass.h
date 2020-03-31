#include "Hand.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#pragma once
class AIClass
{
public:
	
	string name;

	AIClass();
	virtual int chooseCard(Hand hand);
	virtual int chooseFromHand(Hand hand);
	virtual int chooseFromBoard(Card board[5]);
};

