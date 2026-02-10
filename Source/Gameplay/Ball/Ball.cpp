//Ball.cpp
#include "../../Header/Gameplay/Ball/Ball.h"

namespace Gameplay
{
	Ball::Ball()
	{
		current_state = BallState::Idle;
		loadTexture();
		initializeVariables();
	}

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
	}

	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		// Get our sprite
		const Sprite& player1Paddle = player1->getPaddleSprite();
		const Sprite& player2Paddle = player2->getPaddleSprite();

		// Check their bounds
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		// Handle collisions
		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x;
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
	}

	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) || (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
		elapse_delay_time = 0.0f;
		current_state = BallState::Idle;
	}

	void Ball::move(TimeService* time_service)
	{
		updateDelayTime(time_service->getDeltaTime());
		if (current_state == BallState::Moving)
		{
			pong_ball_sprite.move(velocity * time_service->getDeltaTime() * static_cast<float>(speed_multiplier));
		}
	}

	void Ball::updateDelayTime(float delta_time)
	{
		if (current_state == BallState::Idle)
		{
			elapse_delay_time += delta_time;
			if (elapse_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
			}
			else
			{
				return;
			}
		}
	}

	bool Ball::isLeftCollisionOccurred()
	{
		return had_left_collision;
	}

	void Ball::updateLeftCollisionState(bool value)
	{
		had_left_collision = value;
	}

	bool Ball::isRightCollisionOccurred()
	{
		return had_right_collision;
	}

	void Ball::updateRightCollisionState(bool value)
	{
		had_right_collision = value;
	}

	void Ball::handleOutofBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		//Chek for out-of-bounds on the left or right boundary
		if (ball_bounds.left <= left_Boundary)
		{
			updateLeftCollisionState(true);
			reset();
		}
		else if (ball_bounds.left + ball_bounds.width >= right_Boundary)
		{
			updateRightCollisionState(true);
			reset();
		}
	}

	void Ball::update(Paddle* player1, Paddle* player2, TimeService* time_service)
	{
		move(time_service);
		onCollision(player1, player2);
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCollision();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}
}