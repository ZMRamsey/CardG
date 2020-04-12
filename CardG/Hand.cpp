#include "Hand.h"

Hand::Hand()
{
	//one = Card();
	//two = Card();
	//three = Card();
	//four = Card();
	//five = Card();
	step = 1;
}

Hand::Hand(Card cOne, Card cTwo, Card cThree, Card cFour, Card cFive)
{
	one = cOne;
	two = cTwo;
	three = cThree;
	four = cFour;
	five = cFive;
	step = 1;
}

void Hand::addToHand(Card card)
{
	if (getFromInt(1).checkIfNull()) { one = card; }
	else if (getFromInt(2).checkIfNull()) { two = card; }
	else if (getFromInt(3).checkIfNull()) { three = card; }
	else if (getFromInt(4).checkIfNull()) { four = card; }
	else if(getFromInt(5).checkIfNull()) { five = card; }
}

void Hand::fillHand(Card card)
{
	if (step == 1)
	{ 
		one = card;
		step++;
	}
	else if (step == 2)
	{
		two = card;
		step++;
	}
	else if (step == 3)
	{
		three = card;
		step++;
	}
	else if (step == 4)
	{
		four = card;
		step++;
	}
	else if (step == 5)
	{
		five = card;
		step++;
	}
}

Card* Hand::getOne()
{
	return &one;
}

Card* Hand::getTwo()
{
	return &two;
}

Card* Hand::getThree()
{
	return &three;
}

Card* Hand::getFour()
{
	return &four;
}

Card* Hand::getFive()
{
	return &five;
}

Card Hand::getFromInt(int num)
{
	switch (num)
	{
	case 1:
		return *getOne();
	case 2:
		return *getTwo();
	case 3:
		return *getThree();
	case 4:
		return *getFour();
	case 5:
		return *getFive();

	default:
		throw new exception;
	}
}

int Hand::getNoInHand()
{
	int count = 5;
	if (getOne()->checkIfNull()) { count--; }
	if (getTwo()->checkIfNull()) { count--; }
	if (getThree()->checkIfNull()) { count--; }
	if (getFour()->checkIfNull()) { count--; }
	if (getFive()->checkIfNull()) { count--; }

	return count;
}

void Hand::useCard(int num)
{
	switch (num)
	{
	case 1:
		one.isNull = true;
		break;
	case 2:
		two.isNull = true;
		break;
	case 3:
		three.isNull = true;
		break;
	case 4:
		four.isNull = true;
		break;
	case 5:
		five.isNull = true;
		break;

	default:
		break;
	}
}

bool Hand::onlyUsesHand()
{
	for (int i = 0; i < 5; i++)
	{
		//If the card is neither a steal from hand or remove from hand
		if (!(getFromInt(i).getCurrentDisplayName() == "SH") && !(getFromInt(i).getCurrentDisplayName() == "RH"))
		{
			return false;
		}
	}
	return true;
}

void Hand::update(int power)
{
	one.update(power);
	two.update(power);
	three.update(power);
	four.update(power);
	five.update(power);
}
