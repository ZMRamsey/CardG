#include "CardType.h"

CardType::CardType()
{
	type = 0;
	change = 0;
}

CardType::CardType(int type, int change)
{
	this->type = type;
	this->change = change;
}

void CardType::Effect(int* power)
{
	switch (type)
	{
	case 1:
		//power+
		power += change;
		break;
	case 2:
		//power-
		power -= change;
		break;
	case 3:
		//steal from board
		break;
	case 4:
		//steal from hand
		break;
	case 5:
		//remove from board
		break;
	case 6:
		//remove from hand
		break;
	}
}
