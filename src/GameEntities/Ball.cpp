#include "Ball.h"

Ball::Ball(const char* path, SDL_Renderer* renderer, std::pair<int, int> position, int diameter)
	:GameObject(path, renderer, position, std::make_pair(diameter, diameter))
{

}

void Ball::Update(int windowWidth, int windowHight)
{
	dstRect_.x += xSpeed_;
	dstRect_.y += ySpeed_;

	CheckBorderCollision(windowWidth, windowHight);

}

void Ball::CheckBorderCollision(int windowWidth, int windowHight)
{
	if (dstRect_.x < 0 || dstRect_.x + dstRect_.w > windowWidth)
	{
		dstRect_.y = -dstRect_.y;
	}
	if (dstRect_.y < 0)
	{
		dstRect_.y = -dstRect_.y;
	}
}
