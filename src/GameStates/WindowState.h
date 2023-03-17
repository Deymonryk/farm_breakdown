#pragma once
#include <SDL2/SDL.h>
#include "../States.h"

class WindowState
{
protected:
	SDL_Renderer* renderer_;
public:
	WindowState(SDL_Renderer* renderer);
	virtual ~WindowState();
	virtual void handleInput(SDL_Event& e, GameState& gameState) = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

