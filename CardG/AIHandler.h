#pragma once

#include "AIClass.h"

class AIHandler
{
public:
	AIClass* randomAI;
	AIClass* smartAI;
	AIClass* stupidAI;
	
	//Creates one of the 3 different AIs
	AIClass* createAI(int version);
};

