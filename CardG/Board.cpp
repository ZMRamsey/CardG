#include "Hand.h"
#include "Card.h"
#include "CardType.h"
#include "CardBox.h"
#include "Board.h"
#include <stdlib.h>

//Board::Board()
//{
//
//}

void Board::startMatch()
{
	CardBox box;
	box.createCards();

	for (int i = 0; i < 20; i++)
	{
		deck[i] = box.allCards[i];
	}
}

void Board::setPlayerPower(int power)
{
}

void Board::setEnemyPower(int power)
{
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

}

void Board::shuffleCards()
{
	//Take a card from allCards and add it to a random place in a new array

	for (int i = 0; i < 20; i++)
	{
		deck[rand() % 20
	}
}

void Board::logTurn()
{
}
