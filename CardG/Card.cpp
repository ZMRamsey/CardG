#include "Card.h"
#include "CardType.h"

using namespace std;

Card::Card()
{
}

Card::Card(string name, CardType* type1, CardType* type2, int pivot, string displayName1, string displayName2)
{
	this->name = name;
	this->type1 = *type1;
	this->type2 = *type2;
	this->pivot = pivot;
}

void Card::activate(int* power)
{
	activeType.Effect(power);
}

void Card::update(int power)
{
	if (power >= pivot)
	{
		activeType = type2;
		type1Active = false;
	}
	else
	{
		activeType = type1;
		type1Active = true;
	}
}

string Card::getDisplayName1()
{
	return displayName1;
}

string Card::getDisplayName2()
{
	return displayName2;
}

string Card::getCurrentDisplayName()
{
	if (type1Active)
	{
		return displayName1;
	}
	else
	{
		return displayName2;
	}
}

bool Card::getTopHighlight()
{
	return type1Active;
}

bool Card::checkIfNull()
{
	return isNull;
}
