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

	int step;
	//Card nullCard;

	Hand();
	Hand(Card cOne, Card cTwo, Card cThree, Card cFour, Card cFive);
	void addToHand(Card card);
	void fillHand(Card card);
	Card* getOne();
	Card* getTwo();
	Card* getThree();
	Card* getFour();
	Card* getFive();
	Card getFromInt(int);
	int getNoInHand();
	void useCard(int);
	void update(int power);
};

