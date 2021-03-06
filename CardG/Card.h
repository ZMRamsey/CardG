#pragma once

#include <string>
#include "CardType.h"

using namespace std;

class Card
{
public:

	string name;
	string displayName1;
	string displayName2;
	CardType* type1;
	CardType* type2;
	int pivot;
	CardType* activeType;
	bool type1Active;
	bool isNull;

	Card();
	Card(string, CardType*, CardType*, int, string, string);
	void activate(int* power1, int* power2, int* stealRemove);
	void deactivate(int* power1, int* power2);
	void update(int);
	string getDisplayName1();
	string getDisplayName2();
	string getCurrentDisplayName();
	bool getTopHighlight();
	bool checkIfNull();
	void setActive(bool active);
};
