#pragma once
#include <SDL2/SDL.h>
#include <utility>
#include "../TextureManager.h"

class GameObject
{
protected:
	SDL_Texture* texture_;
	SDL_Renderer* renderer_;

	//srcRect - position and size of texture in image file
	//dstRect - position and size of Sprite in the game
	SDL_Rect srcRect_, dstRect_; 
	int xSpeed_, ySpeed_;

public:
	GameObject() {};
	GameObject(const char* path, SDL_Renderer* renderer, 
		std::pair<int, int> position, std::pair<int, int> size); 
	~GameObject();

	virtual void Update(int windowWidth, int windowHight) = 0;
	void Draw();

	void getPosition(int &x, int &y);
	void getSize(int& w, int& h);
	void getSpeed(int& xSpeed, int& ySpeed);

	void setPosition(int x, int y);
	void setSize(int w, int h);
	void setSpeed(int xSpeed, int ySpeed);
};