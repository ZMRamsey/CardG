#include "Card.h"

Card::Card()
{
	name = "Null";
	displayName1 = "XX";
	displayName2 = "XX";
	pivot = 0;
}

Card::Card(string name, CardType* type1, CardType* type2, int pivot, string displayName1, string displayName2)
{
	this->name = name;
	this->type1 = type1;
	this->type2 = type2;
	this->pivot = pivot;
	this->displayName1 = displayName1;
	this->displayName2 = displayName2;
}

void Card::activate(int* power1, int* power2, int* stealNotRemove)
{
	activeType->Effect(power1, power2, stealNotRemove, false);
}

void Card::deactivate(int * power1, int * power2)
{
	int steal = 0;
	activeType->Effect(power1, power2, &steal, true);
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

void Card::setActive(bool active)
{
	isNull = !active;
}
