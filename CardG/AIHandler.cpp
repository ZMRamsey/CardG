#include "AIHandler.h"

AIClass* AIHandler::createAI(int version)
{
	if (version == 1)
	{
		//random AI
		
		class random : public AIClass
		{
		public:
			//Returns valid random number between 1 and 5
			int chooseCard(Hand hand) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5 + 1;
					if (!hand.getFromInt(choice).checkIfNull()) { return choice; }
				}
			}

			//Returns valid random number between 1 and 5
			int chooseFromHand(Hand hand) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5 + 1;
					if (!hand.getFromInt(choice).checkIfNull()) { return choice; }
				}
			}

			//Returns valid random number between 0 and 4
			int chooseFromBoard(Card board [5]) override
			{
				srand(time(NULL));

				while (true)
				{
					int choice = rand() % 5;
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
		class smart : public AIClass
		{
		public:
			int chooseCard(Hand hand) override
			{
				int bestCard = 0;
				
				for (int i = 1; i < 6; i++)
				{
					if (hand.getFromInt(i).checkIfNull() == false)
					{
						if (bestCard == 0)
						{
							bestCard = i;
						}
						else
						{
							if (hand.getFromInt(i).activeType->AIRanking > hand.getFromInt(bestCard).activeType->AIRanking)
							{
								bestCard = i;
							}
						}
					}
				}
				return  bestCard;
			}

			int chooseFromHand(Hand hand) override
			{
				int bestCard = 0;

				for (int i = 1; i < 6; i++)
				{
					if (hand.getFromInt(i).checkIfNull() == false)
					{
						if (bestCard == 0)
						{
							bestCard = i;
						}
						else
						{
							if (hand.getFromInt(i).activeType->AIRanking > hand.getFromInt(bestCard).activeType->AIRanking)
							{
								bestCard = i;
							}
						}
					}
				}
				return  bestCard;
			}

			int chooseFromBoard(Card board[5]) override
			{
				int bestCard = 5;

				for (int i = 0; i < 5; i++)
				{
					if (board[i].checkIfNull() == false)
					{
						if (bestCard == 0)
						{
							bestCard = i;
						}
						else
						{
							if (board[i].activeType->AIRanking > board[bestCard].activeType->AIRanking)
							{
								bestCard = i;
							}
						}
					}
				}
				return  bestCard;
			}
		};

		smartAI = new smart;
		return smartAI;
	}
	else if (version == 3)
	{
		//stupid AI
		//Will always choose the worst card out of the available options
		class stupid : public AIClass
		{
		public:
			int chooseCard(Hand hand) override
			{
				int worstCard = 1;

				for (int i = 1; i < 6; i++)
				{
					if (hand.getFromInt(i).checkIfNull() == false)
					{
						if (worstCard == 0)
						{
							worstCard = i;
						}
						else
						{
							if (hand.getFromInt(i).activeType->AIRanking < hand.getFromInt(worstCard).activeType->AIRanking)
							{
								worstCard = i;
							}
						}
					}
				}
				return  worstCard;
			}

			int chooseFromHand(Hand hand) override
			{
				int worstCard = 1;

				for (int i = 1; i < 6; i++)
				{
					if (hand.getFromInt(i).checkIfNull() == false)
					{
						if (worstCard == 0)
						{
							worstCard = i;
						}
						else
						{
							if (hand.getFromInt(i).activeType->AIRanking < hand.getFromInt(worstCard).activeType->AIRanking)
							{
								worstCard = i;
							}
						}
					}
				}
				return  worstCard;
			}

			int chooseFromBoard(Card board[5]) override
			{
				int worstCard = 1;

				for (int i = 0; i < 5; i++)
				{
					if (board[i].checkIfNull() == false)
					{
						if (worstCard == 0)
						{
							worstCard = i;
						}
						else
						{
							if (board[i].activeType->AIRanking < board[worstCard].activeType->AIRanking)
							{
								worstCard = i;
							}
						}
					}
				}
				return  worstCard;
			}
		};

		stupidAI = new stupid;
		return stupidAI;
	}
}
