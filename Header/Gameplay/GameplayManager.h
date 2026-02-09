//GameplayManager.h
#pragma once
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "Boundary/Boundary.h"
#include "../Event/EventManager.h"

using namespace sf;
using namespace Event;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		float player1_position_x = 80.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1240.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;

		Boundary* boundary;

		EventManager* event_manager;

		void initialize();

	public:
		GameplayManager(EventManager* event_manager);
		void update();
		void render(RenderWindow* game_window);
	};
}