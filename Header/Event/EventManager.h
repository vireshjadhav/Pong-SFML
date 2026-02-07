//EventManager.h
#pragma once
#include <SFML/Graphics.hpp>

namespace Event {
	class EventManager {
	public:
		void pollEvent(sf::RenderWindow* game_window); 		//Process all events

		bool isKeyPressed(sf::Keyboard::Key key);           //Check specific key
	};
}