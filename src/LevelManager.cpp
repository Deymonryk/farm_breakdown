#include "LevelManager.h"

std::vector<Brick*> LevelManager::LoadFromJSON(std::string filePath)
{
	std::ifstream f(filePath);
	json data = json::parse(f);

	std::vector<Brick*> bricks;
	return bricks;
}

void LevelManager::LoadBricksToJSON(std::string filePath, std::vector<Brick*> bricks)
{
	try
	{
		std::ofstream file(filePath);
		json jList;

		for (auto brick : bricks)
		{
			//serialize brick
			json j;
			int x, y;
			int w, h;
			brick->getPosition(x, y);
			brick->getSize(w, h);
			j["dstRect"] = { x, y, w, h };
			j["state"] = brick->getSpriteState();
			j["texturePaths"] = brick->getTexturePathes();

			// Write the JSON to the file with indentation
			jList.push_back(j);
		}
		if (file.is_open())
		{
			file << jList.dump(4);
			file.close();
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Json file with bricks wasn't formed" << std::endl;
	}
}

void LevelManager::LoadPlatformToJSON(std::string filePath, std::unique_ptr<Platform> & platform)
{
	try
	{
		std::ofstream file(filePath);
		json j;

		int x, y;
		int w, h;
		platform->getPosition(x, y);
		platform->getSize(w, h);
		j["dstRect"] = { x, y, w, h };
		j["texturePaths"] = platform->getTexturePathes();
		if (file.is_open())
		{
			file << j.dump(4);
			file.close();
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Json file with platform wasn't formed" << std::endl;
	}
}

void LevelManager::LoadBallToJSON(std::string filePath, std::unique_ptr<Ball> & ball)
{
	try
	{
		std::ofstream file(filePath);
		json j;

		int x, y;
		int diameter;
		ball->getPosition(x, y);
		ball->getSize(diameter, diameter);
		j["dstRect"] = { x, y,diameter };
		j["texturePaths"] = ball->getTexturePathes();
		if (file.is_open())
		{
			file << j.dump(4);
			file.close();
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Json file with ball wasn't formed" << std::endl;
	}
}
