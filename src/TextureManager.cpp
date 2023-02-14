#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* path, SDL_Renderer* renderer)
{
    SDL_Surface* tmp = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);

    if (!texture)
    {
        std::cout << "Failed load texture:\t" << path << std::endl;
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        exit(1);
    }

    return texture;
}
