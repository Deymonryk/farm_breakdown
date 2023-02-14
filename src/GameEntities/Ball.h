#pragma once
#include "GameObject.h"
#include "Platform.h"

class Ball :  public GameObject
{
private:

public:
	Ball(const char* path, SDL_Renderer* renderer, std::pair<int, int> position, int diameter);
	void Update(int windowWidth, int windowHight) override;

	void CheckBorderCollision(int windowWidth, int windowHight);
	void CheckPlatformCollision();
	void CheckBrickCollision();
};

