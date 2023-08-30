#include "Button.h"

Button::Button(std::string pathActive, std::string pathInactive, SDL_Renderer* renderer, SDL_Rect buttonParameters)
	:dstRect_(buttonParameters)
{
	isButtonHovered_ = false;

	activeTexture_ = TextureManager::loadTexture(pathActive, renderer);
	inactiveTexture_ = TextureManager::loadTexture(pathInactive, renderer);
}

Button::Button(std::string pathActive, std::string pathInactive, SDL_Renderer* renderer, SDL_Rect buttonParameters, SDL_Rect textureParameters)
	:dstRect_(buttonParameters), srcRect_(textureParameters)
{
	isButtonHovered_ = false;

	activeTexture_ = TextureManager::loadTexture(pathActive, renderer);
	inactiveTexture_ = TextureManager::loadTexture(pathInactive, renderer);
}

Button::~Button()
{
	SDL_DestroyTexture(activeTexture_);
	SDL_DestroyTexture(inactiveTexture_);
}

void Button::draw(SDL_Renderer* renderer)
{
	if (srcRect_.w == 0 && srcRect_.h == 0)
	{
		if (isButtonHovered_)
		{
			SDL_RenderCopy(renderer, activeTexture_, NULL, &dstRect_);
		}
		else
		{
			SDL_RenderCopy(renderer, inactiveTexture_, NULL, &dstRect_);
		}
	}
	else
	{
		if (isButtonHovered_)
		{
			SDL_RenderCopy(renderer, activeTexture_, &srcRect_, &dstRect_);
		}
		else
		{
			SDL_RenderCopy(renderer, inactiveTexture_, &srcRect_, &dstRect_);
		}
	}
}

void Button::isHovered(int x, int y)
{
	if (x <= dstRect_.x + dstRect_.w && x >= dstRect_.x &&
		y <= dstRect_.y + dstRect_.h && y > dstRect_.y)
	{
		isButtonHovered_ = true;
	}
	else
	{
		isButtonHovered_ = false;
	}
}
