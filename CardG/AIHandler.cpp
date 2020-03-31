#include "AIHandler.h"

AIClass* AIHandler::createAI(int version)
{
	if (version == 1)
	{
		//random AI
		
		class random : public AIClass
		{
		public:
			int chooseCard(Hand hand) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5 + 1;
					if (!hand.getFromInt(choice).checkIfNull()) { return choice; }
				}
			}

			int chooseFromHand(Hand hand) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5 + 1;
					if (!hand.getFromInt(choice).checkIfNull()) { return choice; }
				}
			}

			int chooseFromBoard(Card board [5]) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5 + 1;
					if (!board[choice].checkIfNull()) { return choice; }
				}
			}
		};

		randomAI = new random;
		return randomAI;
	}
	else if (version == 2)
	{
		//smart AI
		smartAI = new AIClass();

	}
	else if (version == 3)
	{
		//stupid AI
		stupidAI = new AIClass();

	}
}
