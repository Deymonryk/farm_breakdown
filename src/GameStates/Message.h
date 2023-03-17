#pragma once
#include "SDL2/SDL.h"
#include <map>
#include "WindowState.h"
#include "../Button.h"
#include "../TextureManager.h"
#include "../States.h"

class Message : public WindowState
{
private:
	SDL_Texture* backgroundTexture_;
	std::map<const char*, Button*> buttons_;
	SDL_Rect dest_;
public:
	Message(SDL_Renderer* renderer, const char* path, std::map<const char*, Button*> buttons, SDL_Rect messageParameters);
	void update() override;
	void handleInput(SDL_Event& e, GameState& gameState) override;
	void draw() override;
};

