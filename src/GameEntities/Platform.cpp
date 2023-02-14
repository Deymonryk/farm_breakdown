#include "Platform.h"

void Platform::CheckBorderCollision(int windowWidth, int windowHight)
{
	if (dstRect_.x < 0 || dstRect_.x > windowWidth)
	{
		dstRect_.x = -dstRect_.x;
	}
}

Platform::Platform(const char* path, SDL_Renderer* renderer, std::pair<int, int> position, std::pair<int,int> size)
	:	GameObject(path, renderer, position, size)
{
	dstRect_.x = position.first - size.first / 2;
	dstRect_.y = position.second;}


void Platform::Update(int windowWidth, int windowHight)
{
	CheckBorderCollision(windowWidth, windowHight);
}