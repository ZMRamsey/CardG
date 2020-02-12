#include "Card.h"

Card::Card(string name, CardType type1, CardType type2, int pivot)
{
	this->name = name;
	this->type1 = type1;
	this->type2 = type2;
	this->pivot = pivot;
}

void Card::activate()
{
}

void Card::update()
{
}
