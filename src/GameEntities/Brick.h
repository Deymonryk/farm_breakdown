#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
private:
	bool isActive_;
public:
	Brick(const char* path, SDL_Renderer* renderer, SDL_Rect objParameters);
	bool getActivity() { return isActive_; };
	void Draw() override;
	void setActivity(bool activity) { isActive_ = activity; };
};

