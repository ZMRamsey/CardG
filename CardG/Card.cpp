#include "Card.h"
#include "CardType.h"

using namespace std;

Card::Card(string name, CardType type1, CardType type2, int pivot)
{
	this->name = name;
	this->type1 = type1;
	this->type2 = type2;
	this->pivot = pivot;
}

void Card::activate()
{
	CardType active;

	activeType.Effect();
}

void Card::update(int power)
{
	if (power >= pivot)
	{
		activeType = type2;
	}
	else
	{
		activeType = type1;
	}
}
