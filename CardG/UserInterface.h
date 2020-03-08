#pragma once
class UserInterface
{
	public:
		void updateGUI(char output);
		char getInput();
		void displayBoard(string, string, int, int, Card*[], Card*[], Hand, Hand);
		void clearScreen();
};

