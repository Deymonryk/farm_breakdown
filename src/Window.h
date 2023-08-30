#pragma once

#include <iostream>
#include "GameStates/Scene.h"
#include "States.h"
#include "GameStates/WindowState.h"
#include "GameStates/MainMenu.h"
#include "GameStates/Message.h"
#include "GameStates/LevelSelectMenu.h"

class Window
{
private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	int width_, height_;
	bool isRunning_;
		
	GameState gameState_;

	Scene* scene_;
	MainMenu* mainMenu_;
	Message* gameoverMessage_;
	Message* victoryMessage_;
	LevelSelectMenu* levelSelectMenu_;
	GameLevels selectedLevel_;

	void CreateWindow(bool isFullscreen);
	void CreateRenderer();

	void loadScene();
	void loadMenu();
	void loadGameoverMessage();
	void loadVictoryMessage();
	void loadLevelSelectMenu();

public:
	Window(int width, int height, bool isFullscreen, std::string windowName);
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

