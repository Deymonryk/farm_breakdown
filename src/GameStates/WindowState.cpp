#include "WindowState.h"

WindowState::WindowState(SDL_Renderer* renderer):
	renderer_(renderer)
{
}

WindowState::~WindowState()
{
	SDL_DestroyRenderer(renderer_);
}
