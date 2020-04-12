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
	Card* card1 = new Card("The Fool", plus1, removeBoard, 5, "+1", "RB"); //really bad card
	Card* card2 = new Card("The Magician", minus1, minus2, 6, "-1", "-3");
	Card* card3 = new Card("The High Priestess", removeHand, stealHand, 5, "RH", "SH");
	Card* card4 = new Card("The Empress", plus2, minus2, 3, "+2", "-2");
	Card* card5 = new Card("The Emperor", plus1, plus4, 8, "+1", "+4");
	Card* card6 = new Card("The Hierophant", plus2, minus2, 4, "+2", "-2"); //basic +2/-2
	Card* card7 = new Card("The Lovers", plus1, stealBoard, 6, "+1", "SB"); //steal from board
	Card* card8 = new Card("The Chariot", removeBoard, minus2, 1, "RB", "-2"); //
	Card* card9 = new Card("Justice", plus3, minus2, 2, "+3", "-2"); //+ when weak, - when strong
	Card* card10 = new Card("The Hermit", plus4, plus1, 1, "+4", "+1"); //big + when weak, small + when strong
	Card* card11 = new Card("Wheel of Fortune", plus1, stealHand, 5, "+1", "SH"); //steal from hand, or rubbish +1
	Card* card12 = new Card("Strength", minus2, plus2, 3, "-2", "+2"); //- when weak, + when strong
	Card* card13 = new Card("The Hanged Man", removeBoard, minus1, 1, "RB", "-1"); //strong when player is very low
	Card* card14 = new Card("Death", plus1, minus4, 8, "+1", "-4"); //super strong -4
	Card* card15 = new Card("Temperance", minus1, plus4, 8, "-1", "+4"); //opposite of death
	Card* card16 = new Card("The Devil", minus3, stealBoard, 6, "-3", "SB"); //steal and -3
	Card* card17 = new Card("The Tower", plus3, minus2, 3, "+3", "-2"); //powerful when weakened
	Card* card18 = new Card("The Star", minus2, plus2, 3, "-2", "+2"); //wish
	Card* card19 = new Card("The Moon", removeHand, stealHand, 5, "RH", "SH"); //hand
	Card* card20 = new Card("The Sun", removeBoard, stealBoard, 5, "RB", "SB"); //board
	Card* card21 = new Card("Judgement", plus3, removeBoard, 5, "+3", "RB"); 
	Card* card22 = new Card("The World", stealHand, plus4, 7, "SH", "+4"); //basic card


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
	allCards[20] = *card21;
	allCards[21] = *card22;

}