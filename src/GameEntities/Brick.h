#pragma once
#include "GameObject.h"

class Brick : public GameObject
{
private:
	SpriteState spriteState_;
	bool isZeroLiveTexture_;
public:
	Brick(std::vector <std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state);
	Brick(std::vector <std::string> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state, bool isZeroLiveTexture);

	void reduceLives();
	void Draw() override;
	void Update() override;

	bool getActivity();
	SpriteState getSpriteState() { return spriteState_; }
	bool isZeroLifeTexture() { return isZeroLiveTexture_; }
};

