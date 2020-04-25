#include "Board.h"

Board::Board()
{

}

void Board::startMatch()
{
	//Instantiate card box
	CardBox box;
	box.createCards();

	//Assign gui
	gui = new UserInterface();

	//Set names
	p1Name = "AI";
	p2Name = gui->getName();

	//Make AI Handler
	AIHandler* handler = new AIHandler();

	//Select AI
	gui->chooseAI();
	while (true)
	{
		char aiSelect = gui->getInput();

		if ((aiSelect - '0' >= 1) && (aiSelect - '0' <= 3))
		{
			ai = handler->createAI(aiSelect - '0');
			break;
		}
	}

	//Create Logger and Log
	loggy = new Logger();
	loggy->newLog();

	//Set marker to beginning of deck
	marker = 0;

	//Copy the cards across to the deck
	for (int i = 0; i < 22; i++)
	{
		deck[i] = box.allCards[i];
	}

	Card nullCard;
	bool shootMEINTHESKULLPLS = true;
	nullCard.isNull = &shootMEINTHESKULLPLS;

	for (int i = 0; i < 5; i++)
	{
		board1[i] = nullCard;
	}
	for (int i = 0; i < 5; i++)
	{
		board2[i] = nullCard;
	}

	//Shuffle the deck
	shuffleCards();

	//Draw cards 5 times and add to hands
	drawCards();

	//Set starting powers
	power1 = 3;
	power2 = 3;

	//Start gameLoop
	bool victory = gameLoop();

	//Win or loss screen
	gui->victoryScreen(victory, power1, power2);
}

bool Board::gameLoop()
{
	char resp;
	int aiChoice;

	while (true)
	{
		hand1.update(power1);
		hand2.update(power2);

		//Enemy goes first
		if (hand1.getNoInHand() > 0)
		{
			//Reset stealRemove
			stealRemove = 0;

			//Draw board
			displayBoard();

			//AI picks card
			aiChoice = ai->chooseCard(hand1);

			//Play AI card
			hand1.getFromInt(aiChoice).activate(&power1, &power2, &stealRemove);

			//Steal or remove
			if (stealRemove != 0)
			{
				aiStealOrRemove();
			}
			else
			{
				playCard(1, hand1.getFromInt(aiChoice));
			}

			//Log move
			logTurn(hand1.getFromInt(aiChoice), false);

			//Set card in hand to null
			hand1.useCard(aiChoice);

		}

		//Draw board
		displayBoard();
		
		//Check endgame conditions
		if ((hand1.getNoInHand() == 0 || hand2.getNoInHand() == 0))
		{
			//1: Neither player has cards
			if ((hand1.getNoInHand() == 0) && (hand2.getNoInHand() == 0))
			{
				//Game is over properly
				return power2 > power1;
			}

			//2: Player 1 has no cards, Player 2 only has steal/remove from hand
			if ((hand1.getNoInHand() == 0) && (hand2.onlyUsesHand() > 0))
			{
				//Calculate scores and end
				power2 += hand2.onlyUsesHand();
				return power2 > power1;
			}

			//3: Player 2 has no cards, Player 1 only has steal/remove from hand
			if ((hand2.getNoInHand() == 0) && (hand1.onlyUsesHand() > 0))
			{
				//Calculate scores and end
				power1 += hand1.onlyUsesHand();
				return power2 > power1;
			}
		}


		//PLAYER TURN
		hand1.update(power1);
		hand2.update(power2);

		//Reset stealRemove
		stealRemove = 0;

		//Draw board
		displayBoard();

		if (hand2.getNoInHand() > 0)
		{
			//Player picks card
			while (true) {
				resp = gui->getInput();

				if (resp == 'q')
				{
					//quit
					return false;
					break;
				}
				if (resp == 'h')
				{
					//Check hand in detail
					resp = displayHand();
				}
				if (resp == '1' || '2' || '3' || '4' || '5')
				{
					try
					{
						int num = resp - '0';
						if (!hand2.getFromInt(num).checkIfNull())
						{
							//pick card
							hand2.getFromInt(num).activate(&power2, &power1, &stealRemove);

							if (stealRemove != 0)
							{
								playerStealOrRemove();
							}
							else
							{
								playCard(2, hand2.getFromInt(num));
							}

							logTurn(hand2.getFromInt(num), true);
							hand2.useCard(num);

							break;
						}
					}
					catch (...)
					{

					}
				}
			}
		}

		//draw board
		displayBoard();
	
		//Check endgame conditions
		if ((hand1.getNoInHand() == 0 || hand2.getNoInHand() == 0))
		{
			//1: Neither player has cards
			if ((hand1.getNoInHand() == 0) && (hand2.getNoInHand() == 0))
			{
				//Game is over properly
				return power2 > power1;
			}

			//2: Player 1 has no cards, Player 2 only has steal/remove from hand
			if ((hand1.getNoInHand() == 0) && (hand2.onlyUsesHand() > 0))
			{
				//Calculate scores and end
				power2 += hand2.onlyUsesHand();
				return power2 > power1;
			}

			//3: Player 2 has no cards, Player 1 only has steal/remove from hand
			if ((hand2.getNoInHand() == 0) && (hand1.onlyUsesHand() > 0))
			{
				//Calculate scores and end
				power1 += hand1.onlyUsesHand();
				return power2 > power1;
			}
		}
	}
	
	return false;
}

void Board::displayBoard()
{
	gui->displayBoard(p1Name, p2Name, power1, power2, board1, board2, hand1, hand2);
}

void Board::setPlayerPower(int power)
{
	power2 += power;
}

void Board::setEnemyPower(int power)
{
	power1 += power;
}

//Adds card to board
bool Board::playCard(int board, Card card)
{
	if (board == 1)
	{
		//Add card to AI board
		for (int i = 0; i < 5; i++)
		{
			if (board1[i].checkIfNull())
			{
				board1[i] = card;
				return true;
			}
		}
		return false;
	}
	else if (board == 2)
	{
		//Add card to player board
		for (int i = 0; i < 5; i++)
		{
			if (board2[i].checkIfNull())
			{
				board2[i] = card;
				return true;
			}
		}
		return false;
	}
	return true;
}

void Board::drawCards()
{	
	char resp;
	for (int i = 0; i < 5; i++)
	{
		//Get random two cards from deck
		//Offer two to player
		//One goes to player hand, one to enemy hand

		Card card1 = deck[marker];
		marker++;
		Card card2 = deck[marker];
		marker++;

		gui->cardSelect(card1, card2);
		while (true) {
			resp = gui->getInput();
			if (resp == '1')
			{
				hand2.fillHand(card1);
				hand1.fillHand(card2);
				break;
			}
			else if (resp == '2')
			{
				hand2.fillHand(card2);
				hand1.fillHand(card1);
				break;
			}

		}
	}

}

void Board::shuffleCards()
{
	srand(time(NULL));
	
	for (int i = 0; i < 200; i++)
	{
		int slot1 = rand() % 20;
		int slot2 = rand() % 20;
		swap(deck[slot1], deck[slot2]);
	}
}

void Board::playerStealOrRemove()
{
	char choice;

	switch (stealRemove)
	{
	case 1:
		//SB
		gui->stealRemoveSelect(true, false, board1, board2, hand1);

		while (true)
		{
			choice = gui->getInput();
			if (choice == '1', '2', '3', '4', '5')
			{
				if (!(board1[choice - '0'].checkIfNull()))
				{
					//card is stolen
					hand2.addToHand(board1[choice - '0']);
					board1[choice - '0'].deactivate(&power1, &power2);
					board1[choice - '0'].setActive(false);
					return;
				}
			}
		}

		break;

	case 2:
		//SH
		gui->stealRemoveSelect(true, true, board1, board2, hand1);

		while (true)
		{
			choice = gui->getInput();
			if (choice == '1', '2', '3', '4', '5')
			{
				if (!hand1.getFromInt(choice - '0').checkIfNull())
				{
					//card is stolen
					hand2.addToHand(board1[choice - '0']);
					hand1.getFromInt(choice - '0').deactivate(&power1, &power2);
					//hand1.getFromInt(choice - '0').setActive(false);
					hand1.useCard(choice = '0');
					return;
				}
			}
		}

		break;

	case 3:
		//RB
		gui->stealRemoveSelect(false, false, board1, board2, hand1);

		while (true)
		{
			choice = gui->getInput();
			if (choice == '1', '2', '3', '4', '5')
			{
				if (!board1[choice - '0' - 1].checkIfNull())
				{
					//card is removed
					board1[choice - '0' - 1].deactivate(&power1, &power2);
					board1[choice - '0' - 1].setActive(false);
					return;
				}
			}
			if (choice == '6', '7', '8', '9', '0')
			{
				if (!board2[choice - '0' - 1].checkIfNull())
				{
					//card is removed
					board2[choice - '0' - 1].deactivate(&power1, &power2);
					board2[choice - '0' - 1].setActive(false);
					return;
				}
			}
		}

		break;

	case 4:
		//RH
		gui->stealRemoveSelect(false, true, board1, board2, hand1);

		while (true)
		{
			choice = gui->getInput();
			if (choice == '1', '2', '3', '4', '5')
			{
				if (!hand1.getFromInt(choice - '0').checkIfNull())
				{
					//card is removed
					hand1.getFromInt(choice - '0').deactivate(&power1, &power2);
					//hand1.getFromInt(choice - '0').setActive(false);
					hand1.useCard(choice-'0');
					return;
				}
			}
		}

		break;

	default:
		break;

	}
}

void Board::aiStealOrRemove()
{
	int aiChoice;

	if (stealRemove == 1 || stealRemove == 3)
	{
		//Board
		aiChoice = ai->chooseFromBoard(board2);
		if (stealRemove == 1)
		{
			//steal
			hand1.addToHand(board2[aiChoice]);
			board2[aiChoice].setActive(false);
		}
		else
		{
			//remove
			board2[aiChoice].setActive(false);
		}
	}
	else if (stealRemove == 2 || stealRemove == 4)
	{
		//Hand
		aiChoice = ai->chooseFromHand(hand2);
		if (stealRemove == 2)
		{
			//steal
			hand1.addToHand(hand2.getFromInt(aiChoice));
			//hand2.getFromInt(aiChoice).setActive(false);
			hand2.useCard(aiChoice);
			return;
		}
		else
		{
			//remove
			//hand2.getFromInt(aiChoice).setActive(false);
			hand2.useCard(aiChoice);
			return;
		}
	}
}

char Board::displayHand()
{
	int cardNum = 1;

	while (true)
	{
		cardNum = gui->viewHand(hand2, cardNum, power2);
		char resp = gui->getInput();

		if (resp == 'b')
		{
			//back
			displayBoard();
			return 'h';
		}
		else if (resp == 'p')
		{
			//Play card
			int chosen = cardNum;
			cardNum++;
			if (cardNum == 6) { cardNum = 1; }
			return (chosen + '0');
		}
		else if (resp == '1')
		{
			//Next
			cardNum++;
			if (cardNum == 6) { cardNum = 1; }
		}
		else if (resp == '2')
		{
			//Previous
			cardNum--;
			if (cardNum == 0) { cardNum = 5; }
		}
	}
}

void Board::logTurn(Card cardUsed, bool playerTurn)
{
	loggy->logTurn(board1, board2, hand1, hand2, power1, power2, p2Name, p1Name, cardUsed, playerTurn);
}
