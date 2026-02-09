//UIService.cpp
#include "../../Header/UI/UIService.h"

namespace UI {
	UIService::UIService() {
		loadFontTexture();
		creatLeftScoreText();
		creatRightScoreText();
	}

	void UIService::loadFontTexture()
	{
		font.loadFromFile(texture_path);
	}

	void UIService::creatLeftScoreText()
	{
		left_score_text.setFont(font);
		left_score_text.setString(initial_string);
		left_score_text.setCharacterSize(font_size);
		left_score_text.setFillColor(font_color);
		left_score_text.setPosition(left_score_position_x, left_score_position_y);
	}

	void UIService::creatRightScoreText()
	{
		right_score_tex.setFont(font);
		right_score_tex.setString(initial_string);
		right_score_tex.setCharacterSize(font_size);
		right_score_tex.setFillColor(font_color);
		right_score_tex.setPosition(right_score_position_x, right_score_position_y);
	}

	void UIService::render(RenderWindow* game_window)
	{
		game_window->draw(left_score_text);
		game_window->draw(right_score_tex);
	}
}