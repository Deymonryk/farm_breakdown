#pragma once
#include "GameObject.h"
#include <utility>

class Platform : public GameObject
{
private:
	void CheckBorderCollision(int windowWidth, int windowHight);
public:
	Platform(const char* path, SDL_Renderer* renderer, std::pair<int, int> position, std::pair<int, int> size);
	void Update(int windowWidth, int windowHight) override;
};

