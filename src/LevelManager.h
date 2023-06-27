#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "GameEntities/Brick.h"

using json = nlohmann::json;

class LevelManager
{
public: 
	std::vector<Brick*> LoadFromJSON(std::string filePath);
	void LoadToJSON(std::string filePath, std::vector<Brick*> bricks);
};

