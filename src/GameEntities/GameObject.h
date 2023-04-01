#pragma once
#include <SDL2/SDL.h>
#include <utility>
#include "../TextureManager.h"
#include "../States.h"
#include <vector>
#include "../States.h"

class GameObject
{
protected:
	std::vector <SDL_Texture*> textures_;
	SDL_Renderer* renderer_;

	//srcRect - position and size of texture in image file
	//dstRect - position and size of Sprite in the game
	SDL_Rect srcRect_, dstRect_; 
	int xSpeed_, ySpeed_;

public:
	GameObject(std::vector <const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters);
	~GameObject();

	virtual void Draw();

	void getPosition(int &x, int &y);
	void getSize(int& w, int& h);
	void getSpeed(int& xSpeed, int& ySpeed);

	void setPosition(double x, double y);
	void setSize(int w, int h);
	void setSpeed(int xSpeed, int ySpeed);
};