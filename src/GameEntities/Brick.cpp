#include "Brick.h"

Brick::Brick(std::vector <std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state)
	:GameObject(texturePathes, renderer, objParameters), spriteState_(state)
{
	isZeroLiveTexture_ = 0;
}

Brick::Brick(std::vector<std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state, bool isZeroLiveTexture)
	:Brick(texturePathes, renderer, objParameters, state)
{
	isZeroLiveTexture_ = isZeroLiveTexture;
}

bool Brick::getActivity()
{
	if (spriteState_ != SpriteState::ZERO_LIFE)
	{
		return true;
	}
	return false;
}

void Brick::reduceLives()
{
	if (spriteState_ != SpriteState::ZERO_LIFE && spriteState_ != SpriteState::INVULNERABLE)
	{
		spriteState_ = static_cast<SpriteState>(static_cast<int>(spriteState_) - 1);
	}
}

void Brick::Draw()
{
	if(!isZeroLiveTexture_)
	{
		switch (spriteState_)
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
	else
	{
		switch (spriteState_)
		{
		case SpriteState::ZERO_LIFE:
			SDL_RenderCopy(renderer_, textures_.at(0), &srcRect_, &dstRect_);
			break;
		case SpriteState::ONE_LIFE:
			SDL_RenderCopy(renderer_, textures_.at(1), &srcRect_, &dstRect_);
			break;
		case SpriteState::TWO_LIVES:
			SDL_RenderCopy(renderer_, textures_.at(2), &srcRect_, &dstRect_);
			break;
		case SpriteState::INVULNERABLE:
			SDL_RenderCopy(renderer_, textures_.at(0), &srcRect_, &dstRect_);
			break;
		default:
			break;
		}
	}
}

void Brick::Update()
{
}
