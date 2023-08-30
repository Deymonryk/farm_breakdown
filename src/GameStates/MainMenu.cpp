#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer, int windowWidth, int windowHeight) : WindowState(renderer)
{
	srand(time(NULL));
	int backroundNumber = rand() % 3 + 1;
	std::string backgroundPath = "data/interface/menuBackground" + std::to_string(backroundNumber) + ".png";
	backGround_ = TextureManager::loadTexture(backgroundPath, renderer_);
	Button *play = new Button("data/interface/playButtonActive.png", "data/interface/playButtonInactive.png", renderer, 
		SDL_Rect{windowWidth / 2 - 50,windowHeight / 2 - 20, 100, 39 });
	menuButtons_.insert(std::pair<std::string, Button*>("play", play));
}

MainMenu::~MainMenu()
{

}

void MainMenu::handleInput(SDL_Event& e, GameState& gameState)
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	for (auto it = menuButtons_.begin(); it != menuButtons_.end(); ++it)
	{
		it->second->isHovered(mouseX, mouseY);
		if (it->second->getHovered() && e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (it->first == "play")
			{
				gameState = GameState::LEVEL_SELECT_MENU;
			}
		}
	}

}

void MainMenu::update()
{
}

void MainMenu::draw()
{
	SDL_RenderCopy(renderer_, backGround_, NULL, NULL);
	for (auto it = menuButtons_.begin(); it != menuButtons_.end(); ++it)
	{
		it->second->draw(renderer_);
	}
}
