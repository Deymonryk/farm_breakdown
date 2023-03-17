#include "GameObject.h"


GameObject::GameObject(const char* path, SDL_Renderer* renderer, SDL_Rect objParameters)
	:renderer_(renderer), dstRect_(objParameters)
{
	texture_ = TextureManager::loadTexture(path, renderer_);
	SDL_QueryTexture(texture_, NULL, NULL, &srcRect_.w, &srcRect_.h);

	setSpeed(0, 0);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture_);
	SDL_RenderClear(renderer_);
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

