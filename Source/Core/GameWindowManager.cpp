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

	void GameWindowManager::render()
	{
		//Clear window with orange color(R:200, G:50, B:50, A:255)
		game_window->clear(Color(200, 50, 50, 255));

		//Display Changes
		game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}