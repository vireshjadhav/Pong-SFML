//GameWindowManage.cpp
#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize()
	{
		//Allocate memory fot the render window object
		game_Window = new RenderWindow();

		//Set up the window with configured properties
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		//Create the window with specific dimensions and title
		game_Window->create(VideoMode(game_window_width, game_window_height), game_title);
	}

	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open, false if closed
		return game_Window->isOpen();
	}

	void GameWindowManager::render()
	{
		// This will handle all the drawing operations
		//It'll be used in future lessons
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_Window;
	}
}