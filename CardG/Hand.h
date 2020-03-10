#include "Card.h"

#pragma once
class Hand
{
public:
	Card one;
	Card two;
	Card three;
	Card four;
	Card five;
	Card nullCard;

	Card getOne();
	Card getTwo();
	Card getThree();
	Card getFour();
	Card getFive();
	Card getFromInt(int);
	int getNoInHand();
	void useCard(int);
	void update();
};

