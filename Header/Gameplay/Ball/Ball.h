//Ball.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Gameplay/Boundary/Boundary.h"
#include "../../Header/Sound/SoundManager.h"


using namespace sf;
using namespace std;
using namespace Sound;

namespace Gameplay
{
	enum class BallState { Idle, Moving };

	class Ball {
	private:
		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		const string texture_path = "Assets/Textures/Ball.png";

		const float scale_x = 0.06f;
		const float scale_y = 0.06f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		const float ball_speed = 50.0f;

		// Horizontal Boundaries
		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		// Vertical Boundaries
		const float left_Boundary = 0.0f;
		const float right_Boundary = 1280.0f;

		//Center position
		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;

		int speed_multiplier = 10;

		float elapse_delay_time = 0.0f;
		float delay_duration = 3.0f;

		BallState current_state;

		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		bool had_left_collision = false;
		bool had_right_collision = false;

		void loadTexture();
		void initializeVariables();
		void move(TimeService* time_service);

		void updateDelayTime(float delta_time);


	public:
		Ball();
		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutofBoundCollision();
		void onCollision(Paddle* player1, Paddle* player2);
		bool isLeftCollisionOccurred();
		void updateLeftCollisionState(bool value);
		bool isRightCollisionOccurred();
		void updateRightCollisionState(bool value);
		void reset();
		void update(Paddle* player1, Paddle* player2, TimeService* time_service);
		void render(RenderWindow* game_window);
	};
}
