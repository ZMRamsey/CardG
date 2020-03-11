#include "CardBox.h"

class StealAndRemove : public Card
{

};

CardBox::CardBox()
{
}

void CardBox::createCards()
{
	//Make all card types
	CardType* plus1 = new CardType(1, 1, "Power +1");
	CardType* plus2 = new CardType(1, 2, "Power +2");
	CardType* plus3 = new CardType(1, 3, "Power +3");
	CardType* plus4 = new CardType(1, 4, "Power +4");

	CardType* minus1 = new CardType(2, 1, "Power -1");
	CardType* minus2 = new CardType(2, 2, "Power -2");
	CardType* minus3 = new CardType(2, 3, "Power -3");
	CardType* minus4 = new CardType(2, 4, "Power -4");

	CardType* stealBoard = new CardType(3, 0, "Steal from Board");
	CardType* stealHand = new CardType(4, 0, "Steal from Hand");

	CardType* removeBoard = new CardType(5, 0, "Remove from Board");
	CardType* removeHand = new CardType(6, 0, "Remove from Hand");

	//Make all cards
	//Might change to tarot
	Card* card1 = new Card("Boost", plus1, plus3, 6, "+1", "+3");
	Card* card2 = new Card("Damage", minus1, minus2, 6, "-1", "-3");
	Card* card3 = new Card("Hand", removeHand, stealHand, 5, "RH", "SH");
	Card* card4 = new Card("Balance", plus2, minus2, 3, "+2", "-2");
	Card* card5 = new Card("Superpower", plus1, plus4, 8, "+1", "+4");
	Card* card6 = new Card("Board", removeBoard, stealBoard, 5, "RB", "SB");
	Card* card7 = new Card("Attack", minus3, stealHand, 7, "-3", "SH");
	Card* card8 = new Card("Resurgance", removeBoard, minus2, 1, "RB", "-2");
	Card* card9 = new Card("Retaliation", minus4, plus1, 2, "-4", "+1");
	Card* card10 = new Card("Pickpocket", stealHand, minus1, 2, "SH", "-1");
	Card* card11 = new Card("Destruction", minus2, removeBoard, 6, "-2", "RB");
	Card* card12 = new Card("Villain", stealHand, removeBoard, 4, "SH", "RB");
	Card* card13 = new Card("Thief", stealHand, stealBoard, 6, "SH", "SB");
	Card* card14 = new Card("Wrecker", removeHand, removeBoard, 6, "RH", "RB");
	Card* card15 = new Card("Bandages", plus4, plus1, 1, "+4", "+1");
	Card* card16 = new Card("Elimination", minus1, minus4, 9, "-1", "-4");
	Card* card17 = new Card("Tactitian", plus3, minus2, 4, "+3", "-2");
	Card* card18 = new Card("Growth", minus2, plus2, 3, "-2", "+2");
	Card* card19 = new Card("idk man", plus3, removeBoard, 5, "+3", "RB");
	Card* card20 = new Card("Temptation", stealHand, plus4, 7, "SH", "+4");


	//Put all cards in array
	allCards[0] = *card1;
	allCards[1] = *card2;
	allCards[2] = *card3;
	allCards[3] = *card4;
	allCards[4] = *card5;
	allCards[5] = *card6;
	allCards[6] = *card7;
	allCards[7] = *card8;
	allCards[8] = *card9;
	allCards[9] = *card10;
	allCards[10] = *card11;
	allCards[11] = *card12;
	allCards[12] = *card13;
	allCards[13] = *card14;
	allCards[14] = *card15;
	allCards[15] = *card16;
	allCards[16] = *card17;
	allCards[17] = *card18;
	allCards[18] = *card19;
	allCards[19] = *card20;

}