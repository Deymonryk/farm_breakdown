#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(std::string path, SDL_Renderer* renderer)
{
    auto pathInChar = path.c_str();
    SDL_Surface* tmp = IMG_Load(pathInChar);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);

    if (!texture)
    {
        std::cout << "Failed load texture:\t" << pathInChar << std::endl;
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        exit(1);
    }

    return texture;
}
