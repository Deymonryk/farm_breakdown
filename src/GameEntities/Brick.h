#pragma once
#include "GameObject.h"

class Brick : public GameObject
{
private:
	//bool isActive_;
	SpriteState spriteState;
public:
	Brick(std::vector <const char*> texturePathes, SDL_Renderer* renderer, SDL_Rect objParameters, SpriteState state);

	void reduceLives();
	void Draw() override;
	void Update() override;

	bool getActivity();
	SpriteState getSpriteState() { return spriteState; }
	//void setActivity(bool activity) { isActive_ = activity; };
};

