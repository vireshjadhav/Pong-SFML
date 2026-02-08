//Paddle.cpp
#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay
{
	Paddle::Paddle(float position_x, float position_y)
	{
		paddle_sprite.setPosition(position_x, position_y);
		loadTexture();
		initializeVariables();
	}

	void Paddle::loadTexture()
	{
		if (!paddle_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load paddle texture!");
		}
	}

	void Paddle::initializeVariables()
	{
		paddle_sprite.setTexture(paddle_texture);
		paddle_sprite.setScale(scale_x, scale_y);
		paddle_sprite.setRotation(90);
	}

	void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		//move up
		if (move_up_key_pressed)
		{
			paddle_sprite.move(0, -paddleSpeed);
		}

		//move down
		if (move_down_key_pressed)
		{
			paddle_sprite.move(0, paddleSpeed);
		}
	}

	void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		movePaddle(move_up_key_pressed, move_down_key_pressed);
	}

	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}
}