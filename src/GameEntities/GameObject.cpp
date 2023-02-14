#include "GameObject.h"


GameObject::GameObject(const char* path, SDL_Renderer* renderer,
	std::pair<int, int> position, std::pair<int, int> size)
	:renderer_(renderer)
{
	texture_ = TextureManager::loadTexture(path, renderer_);
	SDL_QueryTexture(texture_, NULL, NULL, &srcRect_.w, &srcRect_.h);

	setPosition(position.first, position.second);
	setSize(size.first, size.second);
	setSpeed(0, 0);
}

GameObject::~GameObject()
{
	delete texture_;
	delete renderer_;
}

void GameObject::Draw()
{
	SDL_RenderCopy(renderer_, texture_, &srcRect_, &dstRect_);
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

void GameObject::setPosition(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		dstRect_.x = x;
		dstRect_.y = y;
	}
}

void GameObject::setSize(int w, int h)
{
	if (w >= 1 && h >= 1)
	{
		dstRect_.w = w;
		dstRect_.h = h;
	}
}

void GameObject::setSpeed(int xSpeed, int ySpeed)
{
	xSpeed_ = xSpeed;
	ySpeed_ = ySpeed;
}

