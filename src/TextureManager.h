#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>

class TextureManager
{
public:
	static SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
};

