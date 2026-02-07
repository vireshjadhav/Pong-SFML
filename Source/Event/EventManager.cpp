//EventManager.cpp
#include </CPP Projects/Pong-SFML/Header/Event/EventManager.h>

namespace Event {

	void EventManager::pollEvent(sf::RenderWindow* game_window)
	{

		sf::Event event;

		while (game_window->pollEvent(event))
		{
			// Handle window close event
			if (event.type == sf::Event::Closed)
			{
				game_window->close();
			}

			// Handle window close event when escape pressed
			if (isKeyPressed(sf::Keyboard::Escape))
			{
				game_window->close();
			}
		}
	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
}