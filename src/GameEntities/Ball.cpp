#include "Ball.h"

void Ball::reflectX()
{
	xSpeed_ = -xSpeed_;
	dstRect_.x += xSpeed_;
}

void Ball::reflectY()
{
	ySpeed_ = -ySpeed_;
	dstRect_.y += ySpeed_;
}

Ball::Ball(std::vector<std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters)
	:GameObject(texturePathes, renderer, objParameters)
{
}

void Ball::Update()
{
	//move ball
	dstRect_.x += xSpeed_;
	dstRect_.y += ySpeed_;

	//Rotate ball by 15 degrees every frame and render the rotated texture
	currentAngle_ += 15;
	SDL_RenderCopyEx(renderer_, textures_.at(currentTexture_), nullptr, &dstRect_, currentAngle_, nullptr, SDL_FLIP_NONE);
	SDL_RenderPresent(renderer_);
}

void Ball::borderCollision(int maxWidth)
{
	if (dstRect_.x < 0 || dstRect_.x + dstRect_.w > maxWidth)
	{
		reflectX();
	}
	if (dstRect_.y < 0)
	{
		reflectY();
	}
}

void Ball::platformCollision(Platform& platform)
{
	int platX, platY;
	int platW, platH;
	platform.getPosition(platX, platY);
	platform.getSize(platW, platH);
	if (platY < dstRect_.y + dstRect_.h && ySpeed_ > 0)
	{
		if (platX < dstRect_.x + dstRect_.w && platX + platW > dstRect_.x)
		{
			reflectY();
		}
	}
}

void Ball::brickCollision(Brick& brick)
{
	int brickX, brickY;
	int brickW, brickH;
	brick.getPosition(brickX, brickY);
	brick.getSize(brickW, brickH);
	if (dstRect_.x < brickX + brickW && dstRect_.x + dstRect_.w > brickX)
	{
		if (dstRect_.y + dstRect_.h > brickY && dstRect_.y < brickY + brickH)
		{
			int overlapLeft = std::abs	((dstRect_.x + dstRect_.w )	- brickX);
			int overlapRight = std::abs	(dstRect_.x					- (brickX + brickW));
			int overlapTop = std::abs	((dstRect_.y + dstRect_.h)	- brickY);
			int overlapBottom = std::abs(dstRect_.y					- (brickY + brickH));

			int minOverlap = std::min(std::min(overlapLeft, overlapRight), std::min(overlapTop, overlapBottom));

			if (minOverlap == overlapLeft || minOverlap == overlapRight)
			{
				reflectX();
			}
			else if (minOverlap == overlapTop|| minOverlap == overlapBottom)
			{
				reflectY();
			}
			brick.reduceLives();
		}
	}
}

bool Ball::isGameOver(int deathY)
{
	if (dstRect_.y + dstRect_.h > deathY)
	{
		return true;
	}
	return false;
}
