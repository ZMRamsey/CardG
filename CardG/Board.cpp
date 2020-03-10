#include "Hand.h"
#include "Card.h"
#include "CardType.h"
#include "CardBox.h"
#include "UserInterface.h"
#include "Board.h"
#include <stdlib.h>

//Board::Board()
//{
//
//}

void Board::startMatch()
{
	//Instantiate card box
	CardBox box;
	box.createCards();

	//Copy the cards across to the deck
	for (int i = 0; i < 20; i++)
	{
		deck[i] = box.allCards[i];
	}

	//Shuffle the deck
	shuffleCards();

	//Draw cards 5 times and add to hands

	//Assign gui
	gui = new UserInterface();

	//Start gameLoop
	bool victory = gameLoop();

	//Win or loss screen
	if (victory)
	{
		//Win screen
	}
	else
	{
		//Loss screen
	}
}

bool Board::gameLoop()
{
	char resp;
	
	while ((hand1.getNoInHand != 0) && (hand2.getNoInHand != 0))
	{
	//enemy goes first
		//draw board
		displayBoard();
		
		//AI picks card

		//draw board
		displayBoard();

		//card effects
		
		//log

	//player turn
		//draw board
		displayBoard();

		//player picks card
		while (true) {
			resp = gui->getInput();
			int num = resp - '0';

			if ((resp == '1', '2', '3', '4', '5') && (hand2.getFromInt(num).getCurrentDisplayName != "PLACEHOLDER"))
			{
				//pick card
				break;
			}
			else if (resp == 'q')
			{
				//quit
				break;
			}
			else if (resp == 'h')
			{
				//check hand in detail
				break;
			}
		}

		//draw board
		displayBoard();

		//card effects
		//log

	//Check special like steals and removes
	}
	
	return power2 > power1;
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

void Board::playCard()
{
	//Add card to player board
}

void Board::removeCard()
{
	//Remove card from player board
}

void Board::drawCards()
{
	//Get random two cards from deck
	//Offer two to player
	//One goes to player hand, one to enemy hand
	

	marker += 2;

}

void Board::shuffleCards()
{
	for (int i = 0; i < 200; i++)
	{
		int slot1 = rand() % 20;
		int slot2 = rand() % 20;
		Card placeholder = deck[slot1];
		deck[slot1] = deck[slot2];
		deck[slot2] = placeholder;
	}
}

void Board::logTurn()
{
}
