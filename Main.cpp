//Main.cpp
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"

int main()
{
	// Create our window manager instance
	Core::GameWindowManager gameWindowManager;

	// Create an object of event Manager
	Event::EventManager eventManager;

	// Initialize the window
	gameWindowManager.initialize();

	while (gameWindowManager.isGameRunning())
	{
		// Check and process event
		eventManager.pollEvent(gameWindowManager.getGameWindow());

		gameWindowManager.render();
	}

	return 0;
}