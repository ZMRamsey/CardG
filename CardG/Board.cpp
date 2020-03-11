#include "Hand.h"
#include "CardType.h"
#include "CardBox.h"
#include "UserInterface.h"
#include "Board.h"
#include <stdlib.h>
#include <time.h>

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

	p1Name = "AI";
	p2Name = gui->getName();

	//set marker to beginning of deck
	marker = 0;

	//Copy the cards across to the deck
	for (int i = 0; i < 20; i++)
	{
		deck[i] = box.allCards[i];
	}

	Card nullCard;
	nullCard.isNull = true;

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
	
	while (true)
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

			if ((resp == '1', '2', '3', '4', '5') && (!hand2.getFromInt(num).checkIfNull()))
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
	//Check for victory
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

void Board::logTurn()
{
}
