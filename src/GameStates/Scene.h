#pragma once
#include "WindowState.h"
#include "../States.h"
#include "../GameEntities/Ball.h"
#include "../GameEntities/Platform.h"
#include "../GameEntities/Brick.h"
#include "../LevelManager.h"
#include <vector>
#include <json.hpp>
#include <fstream>
#include "../LevelGenerator.h"

class Scene : public WindowState
{
private:
	std::unique_ptr<Platform> platform_;
	std::unique_ptr <Ball> ball_;
	std::vector<Brick*> brickArray_;
	int nActiveBricks_;

	SDL_Texture* sceneBackground_;
	int windowWidth_, windowHeight_;
	
	SceneState sceneState_;

	void LoadGameEntities(GameLevels selectedLevel);
	void LoadBackground(std::string path);
	void LoadPlatform( int platformWidth, int platformHeight);
	void LoadBall(std::vector<std::string> texturePathes, int ballDiameter);

	void LoadLevel1();
	void LoadLevel2();
	void LoadLevel3();
	void LoadLevel4();
	void LoadLevel5();
	void LoadLevel6();

	void CheckBorderCollision();
	void CheckPlatformCollision();
	void CheckBrickCollision();

	void SaveLevelToJSON(std::string levelName);
	void LoadLevelFromJSON(std::string levelName);
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
