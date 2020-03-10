#include "Hand.h"

Card Hand::getOne()
{
	return one;
}

Card Hand::getTwo()
{
	return two;
}

Card Hand::getThree()
{
	return three;
}

Card Hand::getFour()
{
	return four;
}

Card Hand::getFive()
{
	return five;
}

Card Hand::getFromInt(int num)
{
	switch (num)
	{
	case 1:
		return getOne();
	case 2:
		return getTwo();
	case 3:
		return getThree();
	case 4:
		return getFour();
	case 5:
		return getFive();

	default:
		break;
	}
}

int Hand::getNoInHand()
{
	int count = 0;
	if (!getOne().checkIfNull) { count++; }
	if (!getTwo().checkIfNull) { count++; }
	if (!getThree().checkIfNull) { count++; }
	if (!getFour().checkIfNull) { count++; }
	if (!getFive().checkIfNull) { count++; }

	return count;
}

void Hand::useCard(int num)
{
	switch (num)
	{
	case 1:
		one = nullCard;
	case 2:
		two = nullCard;
	case 3:
		three = nullCard;
	case 4:
		four = nullCard;
	case 5:
		five = nullCard;
	}
}

void Hand::update()
{

}
