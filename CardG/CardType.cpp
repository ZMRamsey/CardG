#include "CardType.h"

CardType::CardType()
{
	type = 0;
	change = 0;
	name = " ";
}

CardType::CardType(int type, int change, string name, int ranking)
{
	this->type = type;
	this->change = change;
	this->name = name;
	AIRanking = ranking;
}

void CardType::Effect(int* power, int* enemyPower, int* stealRemove, bool undo)
{
	switch (type)
	{
	case 1:
		//power+
		stealRemove = 0;
		if (undo) { *power -= change; }
		else { *power += change; }
		break;
	case 2:
		//power-
		stealRemove = 0;
		if (undo) { *enemyPower += change; }
		else { *enemyPower -= change; }
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
