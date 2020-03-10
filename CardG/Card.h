#include <string>
#include "CardType.h";

using namespace std;

class Card
{
	string name;
	string displayName1;
	string displayName2;
	CardType type1;
	CardType type2;
	int pivot;
	CardType activeType;
	bool type1Active;
	bool isNull;

	public:
		Card();
		Card(string, CardType*, CardType*, int, string, string);
		void activate(int*);
		void update(int);
		string getDisplayName1();
		string getDisplayName2();
		string getCurrentDisplayName();
		bool getTopHighlight();
		bool checkIfNull();
};
