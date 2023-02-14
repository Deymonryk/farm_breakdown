#pragma once
#include "TextureManager.h"
#include "GameEntities/Ball.h"
#include "GameEntities/Platform.h"

class Scene
{
private:
	Platform* platform_;
	Ball* ball_;

	SDL_Renderer* renderer_;
	SDL_Texture* sceneBackground_;
	int windowWidth_, windowHeight_;

	bool isSceneActie = true;

	void LoadBackground(const char* path);
	void LoadGameEntities();
	void LoadPlatform(const char* path, int platformWidth, int platformHeight);
	void LoadBall(const char* path, int ballDiameter);
public:
	Scene(SDL_Renderer* ren, int wWidth, int wHeight);
	~Scene();
	void Update();
	void Draw();
};
