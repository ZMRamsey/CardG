#include "Logger.h"

void Logger::logTurn()
{
	//Append game data to doc
}

void Logger::newLog()
{
	ifstream log;
	
	//Check for existing log
	if (checkForLog())
	{
		log.open("gameLog.txt", ios::trunc);
	}

	//
}

bool Logger::checkForLog()
{
	ifstream log("gameLog.txt");
	if (log.fail()) {
		//File does not exist code here
		cout << "WARNING: LOG MISSING. GAME WILL NOT BE LOGGED!" << endl;
		return false;
	}
	//otherwise, file exists
	return true;
}
