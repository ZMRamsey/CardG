#include "CardType.h"

CardType::CardType()
{
	type = 0;
	change = 0;
	name = " ";
}

CardType::CardType(int type, int change, string name)
{
	this->type = type;
	this->change = change;
	this->name = name;
}

void CardType::Effect(int* power, int* enemyPower, int* stealRemove)
{
	switch (type)
	{
	case 1:
		//power+
		stealRemove = 0;
		*power += change;
		break;
	case 2:
		//power-
		stealRemove = 0;
		*enemyPower -= change;
		break;
	case 3:
		//steal from board
		*stealRemove = 1;
		break;
	case 4:
		//steal from hand
		*stealRemove = 2;
		break;
	case 5:
		//remove from board
		*stealRemove = 3;
		break;
	case 6:
		//remove from hand
		*stealRemove = 4;
		break;
	}
}
