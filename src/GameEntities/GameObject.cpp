#include "GameObject.h"


GameObject::GameObject(std::vector <std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters)
	:renderer_(renderer), dstRect_(objParameters), texturePathes_(texturePathes)
{
	for (auto path : texturePathes)
	{
		textures_.push_back(TextureManager::loadTexture(path, renderer_));
	}
	SDL_QueryTexture(textures_.at(0), NULL, NULL, &srcRect_.w, &srcRect_.h);
	currentTexture_ = 0;

	setSpeed(0, 0);
}

GameObject::~GameObject()
{
	textures_.clear();
	SDL_RenderClear(renderer_);
}

void GameObject::Draw()
{
	SDL_RenderCopy(renderer_, textures_.at(currentTexture_), &srcRect_, &dstRect_);
}

void GameObject::Update()
{
	if(textures_.size() > 1)
	{
		frameCount_++;
		//change the number after % to change number of frame where texture changes
		if (frameCount_ % 3 == 0)
		{
			currentTexture_++;
			if (currentTexture_ >= textures_.size())
			{
				currentTexture_ = 0;
			}
			frameCount_ = 0;
		}
	}
}

void GameObject::getPosition(int& x, int& y)
{
	x = dstRect_.x;
	y = dstRect_.y;
}

void GameObject::getSize(int& w, int& h)
{
	w = dstRect_.w;
	h = dstRect_.h;
}

void GameObject::getSpeed(int& xSpeed, int& ySpeed)
{
	xSpeed = xSpeed_;
	ySpeed = ySpeed_;
}

void GameObject::setPosition(double x, double y)
{
	dstRect_.x = x;
	dstRect_.y = y;
}

void GameObject::setSize(int w, int h)
{
	dstRect_.w = w;
	dstRect_.h = h;
}

void GameObject::setSpeed(int xSpeed, int ySpeed)
{
	xSpeed_ = xSpeed;
	ySpeed_ = ySpeed;
}


