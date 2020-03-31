#pragma once

#include "AIClass.h"

class AIHandler
{
public:
	AIClass* randomAI;
	AIClass* smartAI;
	AIClass* stupidAI;
	
	AIClass* createAI(int version);
};

