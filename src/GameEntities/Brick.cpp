#include "Brick.h"

Brick::Brick(std::vector <const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state)
	:GameObject(texturePathes, renderer, objParameters), spriteState(state)
{
}

bool Brick::getActivity()
{
	if (spriteState != SpriteState::ZERO_LIFE)
	{
		return true;
	}
	return false;
}

void Brick::reduceLives()
{
	if (spriteState != SpriteState::ZERO_LIFE)
	{
		spriteState = static_cast<SpriteState>(static_cast<int>(spriteState) - 1);
	}
}

void Brick::Draw()
{
	switch (spriteState)
	{
	case SpriteState::ZERO_LIFE:
		break;
	case SpriteState::ONE_LIFE:
		SDL_RenderCopy(renderer_, textures_.at(0), &srcRect_, &dstRect_);
		break;
	case SpriteState::TWO_LIVES:
		SDL_RenderCopy(renderer_, textures_.at(1), &srcRect_, &dstRect_);
		break;
	case SpriteState::INVULNERABLE:
		SDL_RenderCopy(renderer_, textures_.at(0), &srcRect_, &dstRect_);
		break;
	default:
		break;
	}
}
