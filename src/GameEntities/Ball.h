#pragma once
#include "GameObject.h"
#include "Platform.h"
#include "Brick.h"

class Ball :  public GameObject
{
private:
	void reflectX();
	void reflectY();
public:
	Ball(std::vector<const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters);
	void Update();

	void borderCollision(int maxWidth);
	void platformCollision(Platform& platform);
	void brickCollision(Brick& brick);

	bool isGameOver(int deathY);
};

