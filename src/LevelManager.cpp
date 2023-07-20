#include "LevelManager.h"

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
			j["zeroLifeTexture"] = brick->isZeroLifeTexture();

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

std::vector<Brick*> LevelManager::LoadBricksFromJSON(std::string filePath, SDL_Renderer* renderer, int& nActiveBricks)
{
	std::ifstream file(filePath);
	json data = json::parse(file);

	std::vector<Brick*> bricks;
	for (auto brickData : data)
	{
		// Deserialize brick data
		int x = brickData["dstRect"][0];
		int y = brickData["dstRect"][1];
		int w = brickData["dstRect"][2];
		int h = brickData["dstRect"][3];
		SpriteState state = brickData["state"];
		if (state != SpriteState::ZERO_LIFE && state != SpriteState::INVULNERABLE)
		{
			nActiveBricks++;
		}
		bool isZeroLifeTexture = false;
		if (brickData.contains("zeroLifeTexture"))
		{
			isZeroLifeTexture = brickData["zeroLifeTexture"];
		}

		// Convert the JSON array to std::vector<std::string>
		std::vector<std::string> texturePaths = brickData["texturePaths"].get<std::vector<std::string>>();
		Brick* brick = new Brick(texturePaths, renderer, SDL_Rect { x,y,w,h }, state, isZeroLifeTexture);
		bricks.push_back(brick);
	}
	return bricks;
}

std::unique_ptr<Platform> LevelManager::LoadPlatformFromJSON(std::string filePath, SDL_Renderer* renderer)
{
	std::ifstream file(filePath);

	json data = json::parse(file);

	int x = data["dstRect"][0];
	int y = data["dstRect"][1];
	int w = data["dstRect"][2];
	int h = data["dstRect"][3];

	std::vector<std::string> texturePaths = data["texturePaths"].get<std::vector<std::string>>();
	auto platform = std::make_unique<Platform>(texturePaths, renderer, SDL_Rect{ x, y, w, h }, 50);
	return platform;
}

std::unique_ptr<Ball> LevelManager::LoadBallFromJSON(std::string filePath, SDL_Renderer* renderer)
{
	std::ifstream file(filePath);
	json data = json::parse(file);

	int x = data["dstRect"][0];
	int y = data["dstRect"][1];
	int w = data["dstRect"][2];

	std::vector<std::string> texturePaths = data["texturePaths"].get<std::vector<std::string>>();
	std::unique_ptr<Ball> ball = std::make_unique<Ball>(texturePaths, renderer, SDL_Rect{ x, y, w, w });
	return ball;
}

