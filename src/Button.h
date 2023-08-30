#pragma once
#include <SDL2/SDL.h>
#include <algorithm>
#include "TextureManager.h"

class Button
{
protected:
    SDL_Rect dstRect_;
    SDL_Rect srcRect_;
    SDL_Texture* activeTexture_;
    SDL_Texture* inactiveTexture_;
    bool isButtonHovered_;
public:
    //use if texture file contains single texture
    Button(std::string pathAcrive, std::string pathInactive, SDL_Renderer* renderer, SDL_Rect buttonParameters);
    //use if texture file contains multiple textures: textureParameters used to define textures x, y, w, h
    Button(std::string pathActive, std::string pathInactive, SDL_Renderer* renderer, SDL_Rect buttonParameters, SDL_Rect textureParameters);
    ~Button();

    bool getHovered() { return isButtonHovered_; };

    void draw(SDL_Renderer* renderer);
    void isHovered(int x, int y);
};

