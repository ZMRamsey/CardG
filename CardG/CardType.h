#pragma once

#include <string>

using namespace std;

class CardType
{
public:
	string name;

	//1: Power+
	//2: Power-
	//3: Steal from board
	//4: Steal from hand
	//5: Remove from board
	//6: Remove from hand
	int type;

	//Level of power+/-
	int change;
	
	
	CardType();
	CardType(int type, int change, string name);
	void Effect(int* power, int* enemyPower, int* stealRemove);
};

