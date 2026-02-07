//GameWindowManager.h
#pragma once
#include <SFML/Graphics.hpp>

namespace Core {
	using namespace sf;

	class GameWindowManager
	{
	private:
		int game_window_width = 1280;
		int game_window_height = 720;

		std::string game_title = "SFML - Pong!";

		RenderWindow* game_window;

		void creatGameWindow();


	public:
		void initialize();
		RenderWindow* getGameWindow();
		bool isGameRunning();
		void render();
	};
}