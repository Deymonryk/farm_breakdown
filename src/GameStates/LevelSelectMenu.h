#pragma once
#include "WindowState.h"

class LevelSelectMenu : public WindowState
{
	SDL_Texture* backgroundTexture_;
	std::map<const char*, Button*> buttons_;
	SDL_Rect dest_;
	GameLevels selectedLevel_;
public:
	LevelSelectMenu(SDL_Renderer* renderer, const char* path, std::map<const char*, Button*> buttons, SDL_Rect menuParameters);
	void update() override;
	void handleInput(SDL_Event& e, GameState& gameState) override;
	void draw() override;

	GameLevels getSelectedLevel() { return selectedLevel_; };
};

