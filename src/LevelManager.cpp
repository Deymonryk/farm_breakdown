#include "LevelManager.h"

std::vector<Brick*> LevelManager::LoadFromJSON(std::string filePath)
{
	std::ifstream f(filePath);
	json data = json::parse(f);

	std::vector<Brick*> bricks;
	return bricks;
}

void LevelManager::LoadToJSON(std::string filePath, std::vector<Brick*> bricks)
{

}
