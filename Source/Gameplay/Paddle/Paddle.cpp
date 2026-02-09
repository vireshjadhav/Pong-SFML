//Paddle.cpp
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Gameplay/Boundary/Boundary.h"

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

	void Paddle::reset(float position_x, float position_y)
	{
		paddle_sprite.setPosition(position_x, position_y);
	}

	Sprite Paddle::getPaddleSprite()
	{
		return paddle_sprite;
	}

	void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service)
	{
		//move up
		if (move_up_key_pressed && paddle_sprite.getPosition().y > topBoundary)
		{
			paddle_sprite.move(0, -paddleSpeed * time_service->getDeltaTime() * speedMultiplier);
		}

		FloatRect paddle_Bounds = paddle_sprite.getGlobalBounds();

		//move down
		if (move_down_key_pressed && paddle_sprite.getPosition().y + paddle_Bounds.height < bottomBoundary)
		{
			paddle_sprite.move(0, paddleSpeed * time_service->getDeltaTime() * speedMultiplier);
		}
	}

	void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service)
	{
		movePaddle(move_up_key_pressed, move_down_key_pressed,time_service);
	}

	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}
}
