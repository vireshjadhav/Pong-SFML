//GameWindowManager.cpp
#include <../../Header/Core/GameWindowManager.h>

using namespace sf;

namespace Core {

	void GameWindowManager::initialize()
	{
		//Allocate memory fot the render window object
		game_window = new RenderWindow();

		//Set up the window with configured properties
		creatGameWindow();
	}

	void GameWindowManager::creatGameWindow()
	{
		//Create the window with specific dimensions and title
		game_window->create(VideoMode(game_window_width, game_window_height), game_title, sf::Style::Default);
	}

	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open, false if closed
		return game_window->isOpen();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}

	void GameWindowManager::displayGameWindow()
	{
		return game_window->display();
	}
}