//GameWindowManage.cpp
#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize()
	{
		//Allocate memory fot the render window object
		game_window = new RenderWindow();

		//Set up the window with configured properties
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		//Create the window with specific dimensions and title
		game_window->create(
			sf::VideoMode::getDesktopMode(),
			game_title,
			sf::Style::Fullscreen
			);
	}

	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open, false if closed
		return game_window->isOpen();
	}

	void GameWindowManager::render()
	{
		//Clear window with orange color(R:200, G:50, B:50, A:255)
		game_window->clear(sf::Color(200, 50, 50, 255));

		//Display the Changes
		game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}