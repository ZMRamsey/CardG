#include "Logger.h"

using namespace std;

Logger::Logger()
{
}

void Logger::logTurn(Card board1[5], Card board2[5], Hand enemyHand, Hand playerHand, int power1, int power2, string playerName, string AI, Card cardPlayed, bool playerTurn)
{
	//Append game data to doc
	ofstream log("gameLog.txt", ios::app);
	
	log << "TURN " << turnCount << "\n" << endl;
	
	Card logCard;

	//Log AI's hand
	log << AI << "'s Hand:" << endl;
	for (int i = 1; i < 6; i++)
	{
		logCard = enemyHand.getFromInt(i);
		if (logCard.checkIfNull() == false)
		{
			log << logCard.name << "  ( " << logCard.type1->name << ", " << logCard.type2->name << " )  PIVOT: " << logCard.pivot << endl;
		}
	}

	//Log Player's hand
	log << playerName << "'s Hand:" << endl;
	for (int i = 1; i < 6; i++)
	{
		logCard = playerHand.getFromInt(i);
		if (logCard.checkIfNull() == false)
		{
			log << logCard.name << "  ( " << logCard.type1->name << ", " << logCard.type2->name << " )  PIVOT: " << logCard.pivot << endl;
		}
	}

	//Log Board
	log << "\n=====The Board=====" << endl;
	
	string boardStrings[5];

	for (int i = 0; i < 5; i++)
	{
		if (board1[i].checkIfNull() == false)
		{
			boardStrings[i] = board1[i].getCurrentDisplayName();
		}
		else
		{
			boardStrings[i] = "--";
		}
	}
	log << boardStrings[0] << "  " << boardStrings[1] << "  " << boardStrings[2] << "  " << boardStrings[3] << "  " << boardStrings[4] << "  " << endl;

	for (int i = 0; i < 5; i++)
	{
		if (board2[i].checkIfNull() == false)
		{
			boardStrings[i] = board2[i].getCurrentDisplayName();
		}
		else
		{
			boardStrings[i] = "--";
		}
	}
	log << "\n" << boardStrings[0] << "  " << boardStrings[1] << "  " << boardStrings[2] << "  " << boardStrings[3] << "  " << boardStrings[4] << "  " << endl;

	//Log the turn that has just happened
	string turnName;
	if (playerTurn) { turnName = playerName; }
	else { turnName = AI; }
	
	log << "\n" << turnName << " played " << cardPlayed.name << " while it had the effect " << cardPlayed.activeType->name << endl;

	//Log power levels
	log << playerName << "'s Power Level: " << power2 << endl;
	log << AI << "'s Power Level: " << power1 << endl;

	log << "\n \n \n" << endl;
	turnCount++;

}

void Logger::newLog()
{
	ofstream log("gameLog.txt", ios::out);
	if (!log)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	
	log << "========GAME LOG========" << endl;

	log.close();
}
