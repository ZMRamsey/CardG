#pragma once
class Board
{
	int power1;
	int power2;
	bool turn;
	string p1Name;
	string p2Name;
	Card board1[5];
	Card board2[5];
	Card deck[20];
	Hand hand1;
	Hand hand2;

public:
	Board();
	void startMatch();
	void setPlayerPower(int power);
	void setEnemyPower(int power);
	void playCard();
	void removeCard();
	void drawCards();
	void shuffleCards();
	void logTurn();
};
