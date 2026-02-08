//Paddle.h
#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
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

		void loadTexture();
		void initializeVariables();

	public:
		Paddle(float position_x, float position_y);
		void update();
		void render(RenderWindow* game_window);
	};
}