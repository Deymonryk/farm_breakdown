#pragma once
#include "GameObject.h"
#include <utility>

class Platform : public GameObject
{
private:
	
public:
	Platform(std::vector<const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, int xSpeed);
	void CheckBorderCollision(int maxWidth);
};

