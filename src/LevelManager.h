#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "GameEntities/Brick.h"
#include "GameEntities/Platform.h"
#include "GameEntities/Ball.h"

using json = nlohmann::json;

class LevelManager
{
public: 
	std::vector<Brick*> LoadFromJSON(std::string filePath);

	static void LoadPlatformToJSON(std::string filePath, std::unique_ptr<Platform> & platform);
	static void LoadBallToJSON(std::string filePath, std::unique_ptr<Ball> & ball);
	static void LoadBricksToJSON(std::string filePath, std::vector<Brick*> bricks);
};

