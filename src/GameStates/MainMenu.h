#pragma once
#include "WindowState.h"
#include "../Button.h"
#include <map>

class MainMenu : public WindowState
{
private:
	SDL_Texture* backGround_;
	std::map<const char*, Button*> menuButtons_;

public:
	MainMenu(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	~MainMenu();

	void handleInput(SDL_Event& e, GameState& gameState) override;
	void update() override;
	void draw() override;
};

