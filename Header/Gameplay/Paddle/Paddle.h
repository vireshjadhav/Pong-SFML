//Paddle.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Utility/TimeService.h"

using namespace std;
using namespace sf;
using namespace Utility;
namespace Gameplay
{

	class Paddle {
	private:
		Texture paddle_texture;
		Sprite paddle_sprite;

		const string texture_path = "Assets/Textures/Paddle.png";

		const float scale_x = 0.2f;
		const float scale_y = 0.2f;

		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;

		const float topBoundary = 20.0f;
		const float bottomBoundary = 700.0f;

		const float paddleSpeed = 20.0f;

		int speedMultiplier = 10;

		void loadTexture();
		void initializeVariables();
		void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);

	public:
		Paddle(float position_x, float position_y);
		void reset(float positionx, float position_y);

		Sprite getPaddleSprite();
		void update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);
		void render(RenderWindow* game_window);
	};
}

