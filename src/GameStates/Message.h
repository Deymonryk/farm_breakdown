#pragma once
#include "WindowState.h"

class Message : public WindowState
{
private:
	SDL_Texture* backgroundTexture_;
	std::map<std::string, Button*> buttons_;
	SDL_Rect dest_;
public:
	Message(SDL_Renderer* renderer, std::string path, std::map<std::string, Button*> buttons, SDL_Rect messageParameters);
	void update() override;
	void handleInput(SDL_Event& e, GameState& gameState) override;
	void draw() override;
};

