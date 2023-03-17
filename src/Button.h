#pragma once
#include <SDL2/SDL.h>
#include <algorithm>
#include "TextureManager.h"

class Button
{
protected:
    SDL_Rect rect_;
    SDL_Texture* activeTexture_;
    SDL_Texture* inactiveTexture_;
    bool hovered_;
public:
    Button(const char* pathAcrive, const char* pathInactive, SDL_Renderer* renderer, 
        std::pair<int, int> position);
    ~Button();

    bool getHovered() { return hovered_; };

    void draw(SDL_Renderer* renderer);
    void isHovered(int x, int y);
};

