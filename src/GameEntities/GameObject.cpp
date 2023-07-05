#include "GameObject.h"


GameObject::GameObject(std::vector <const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters)
	:renderer_(renderer), dstRect_(objParameters)
{
	for (auto path : texturePathes)
	{
		textures_.push_back(TextureManager::loadTexture(path, renderer_));
	}
	SDL_QueryTexture(textures_.at(0), NULL, NULL, &srcRect_.w, &srcRect_.h);
	currentTexture = 0;

	setSpeed(0, 0);
}

GameObject::~GameObject()
{
	textures_.clear();
	SDL_RenderClear(renderer_);
}

void GameObject::Draw()
{
	SDL_RenderCopy(renderer_, textures_.at(currentTexture), &srcRect_, &dstRect_);
}

void GameObject::Update()
{
	if(textures_.size() > 1)
	{
		int r = rand() % 3;
		if (r % textures_.size() == 0)
		{
			currentTexture++;
			if (currentTexture >= textures_.size())
			{
				currentTexture = 0;
			}
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


