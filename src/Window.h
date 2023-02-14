#pragma once

#include <iostream>
#include "Scene.h"

class Window
{
private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	int width_, height_;
	bool isRunning_;

	Scene* scene_;

	void CreateWindow(bool isFullscreen);
	void CreateRenderer();

	void loadScene();
public:
	Window(int width, int height, bool isFullscreen);
	~Window();
	void Quit();

	void ProcessInputs();
	void UpdateWindow();
	void Draw();
	bool running() { return isRunning_; };
	void setRunning(bool state) { isRunning_ = state; };

	void getSize(int& w, int& h);
	SDL_Renderer* getRenderer() { return renderer_; };
};

