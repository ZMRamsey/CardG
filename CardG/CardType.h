#pragma once
class CardType
{
	//1: Power+
	//2: Power-
	//3: Steal from board
	//4: Steal from hand
	//5: Remove from board
	//6: Remove from hand
	int type;

	//Level of power+/-
	int change;

public:
	CardType();
	CardType(int type, int change);
	void Effect(int* power);
};

