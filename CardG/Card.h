#include <string>
#include "CardType.h";

using namespace std;

class Card
{
	string name;
	CardType type1;
	CardType type2;
	int pivot;
	CardType activeType;

	public:
		Card(string, CardType, CardType, int);
		void activate();
		void update(int);

};
