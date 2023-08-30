#pragma once
#include "WindowState.h"
#include <string>

class MainMenu : public WindowState
{
private:
	SDL_Texture* backGround_;
	std::map<std::string, Button*> menuButtons_;

public:
	MainMenu(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	~MainMenu();

	void handleInput(SDL_Event& e, GameState& gameState) override;
	void update() override;
	void draw() override;
};

