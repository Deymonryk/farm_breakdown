#include "Platform.h"

void Platform::CheckBorderCollision(int maxWidth)
{
	if (dstRect_.x < 0 || dstRect_.x > maxWidth)
	{
		dstRect_.x = -dstRect_.x;
	}
}

Platform::Platform(std::vector<const char*> texturePathes, SDL_Renderer* renderer,
	SDL_Rect objParameters, int xSpeed)
	: GameObject(texturePathes, renderer, objParameters)
{
	xSpeed_ = xSpeed;
}

