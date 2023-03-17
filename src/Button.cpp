#include "Button.h"

Button::Button(const char* pathActive, const char* pathInactive, SDL_Renderer* renderer, 
	std::pair<int, int> position)
{
	hovered_ = false;

	activeTexture_ = TextureManager::loadTexture(pathActive, renderer);
	inactiveTexture_ = TextureManager::loadTexture(pathInactive, renderer);

	int activeWidth, activeHeight;
	int inactiveWidth, inactiveHeight;
	SDL_QueryTexture(activeTexture_, NULL, NULL, &activeWidth, &activeHeight);
	SDL_QueryTexture(activeTexture_, NULL, NULL, &inactiveWidth, &inactiveHeight);

	if (activeWidth == inactiveWidth && activeHeight == inactiveHeight)
	{
		rect_.w = activeWidth;
		rect_.h = activeHeight;
	}

	rect_.x = position.first;
	rect_.y = position.second;
}

Button::~Button()
{
	SDL_DestroyTexture(activeTexture_);
	SDL_DestroyTexture(inactiveTexture_);
}

void Button::draw(SDL_Renderer* renderer)
{
	if (hovered_)
	{
		SDL_RenderCopy(renderer, activeTexture_, NULL, &rect_);
	}
	else
	{
		SDL_RenderCopy(renderer, inactiveTexture_, NULL, &rect_);
	}
}

void Button::isHovered(int x, int y)
{
	if (x <= rect_.x + rect_.w && x >= rect_.x &&
		y <= rect_.y + rect_.h && y > rect_.y)
	{
		hovered_ = true;
	}
	else
	{
		hovered_ = false;
	}
}
