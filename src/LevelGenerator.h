#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "GameEntities/Brick.h"
#include "LevelManager.h"

class LevelGenerator
{
public:
	static void GenerateLevel1Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	static void GenerateLevel2Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	static void GenerateLevel3Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	static void GenerateLevel4Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	static void GenerateLevel5Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);
	static void GenerateLevel6Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight);

	static void GenerateFarmFences(SDL_Renderer* renderer, std::vector<Brick*> &brickArray);
};