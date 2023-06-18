#pragma once
#include "WindowState.h"
#include "../States.h"
#include "../GameEntities/Ball.h"
#include "../GameEntities/Platform.h"
#include "../GameEntities/Brick.h"
#include <vector>


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

	void LoadGameEntities(GameLevels selectedLevel);
	void LoadBackground(const char* path);
	void LoadPlatform(std::vector<const char*> texturePathes, int platformWidth, int platformHeight);
	void LoadBall(std::vector<const char*> texturePathes, int ballDiameter);
	void LoadBricks(std::vector<const char*> texturePathes, int verticalNumber, int horizontalNumber, SpriteState spriteState);

	void CheckBorderCollision();
	void CheckPlatformCollision();
	void CheckBrickCollision();
public:
	Scene(SDL_Renderer* ren, int wWidth, int wHeight, GameLevels selectedLevel);
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
