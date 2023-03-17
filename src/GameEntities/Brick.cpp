#include "Brick.h"

Brick::Brick(const char* path, SDL_Renderer* renderer, SDL_Rect objParameters)
	:GameObject(path, renderer, objParameters)
{
	isActive_ = true;
}

void Brick::Draw()
{
	if (isActive_)
	{
		SDL_RenderCopy(renderer_, texture_, &srcRect_, &dstRect_);
	}
}
