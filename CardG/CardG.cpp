#include "UserInterface.h"

int main()
{
	UserInterface gui;

	char response;

	response = gui.getInput();

	gui.updateGUI(response);
}
