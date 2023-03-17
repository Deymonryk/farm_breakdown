#pragma once
#include <vector>
#include "WindowState.h"
#include "../TextureManager.h"
#include "../GameEntities/Ball.h"
#include "../GameEntities/Platform.h"
#include "../GameEntities/Brick.h"
#include "../States.h"

class Scene : public WindowState
{
private:
	Platform* platform_;
	Ball* ball_;
	std::vector<std::vector<Brick*>> brickArray_;
	int nActiveBricks_;

	SDL_Texture* sceneBackground_;
	int windowWidth_, windowHeight_;

	SceneState sceneState_;

	void LoadGameEntities();
	void LoadBackground(const char* path);
	void LoadPlatform(const char* path, int platformWidth, int platformHeight);
	void LoadBall(const char* path, int ballDiameter);
	void LoadBricks(const char* path, int verticalNumber, int horizontalNumber);

	void CheckBorderCollision();
	void CheckPlatformCollision();
	void CheckBrickCollision();
public:
	Scene(SDL_Renderer* ren, int wWidth, int wHeight);
	~Scene();
	void update() override;
	void draw() override;
	void handleInput(SDL_Event &e, GameState &gameState) override;
	void loadGame(int mouseX, int mouseY);
	int getNumActiveBricks() { return nActiveBricks_; };

	bool isSceneActive();
	bool isGameOver();
	bool isVictory();

	void movePlatformLeft();
	void movePlatformRight();
};
