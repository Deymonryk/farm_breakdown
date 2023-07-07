#include "LevelSelectMenu.h"

LevelSelectMenu::LevelSelectMenu(SDL_Renderer* renderer, std::string path, std::map<std::string, Button*> buttons, SDL_Rect menuParameters)
	:WindowState(renderer), buttons_(buttons), dest_(menuParameters)
{
	backgroundTexture_ = TextureManager::loadTexture(path, renderer_);
}

void LevelSelectMenu::update()
{
}

void LevelSelectMenu::handleInput(SDL_Event& e, GameState& gameState)
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->isHovered(mouseX, mouseY);
		if (it->second->getHovered() && e.type == SDL_MOUSEBUTTONDOWN)
		{
			gameState = GameState::SCENE;
			if (it->first == "Level1")
			{
				selectedLevel_ = GameLevels::Level1;
			}
			else if (it->first == "Level2")
			{
				selectedLevel_ = GameLevels::Level2;
			}
			else if (it->first == "Level3")
			{
				selectedLevel_ = GameLevels::Level3;
			}
			else if (it->first == "Level4")
			{
				selectedLevel_ = GameLevels::Level4;
			}
			else if (it->first == "Level5")
			{
				selectedLevel_ = GameLevels::Level5;
			}
			else if (it->first == "Level6")
			{
				selectedLevel_ = GameLevels::Level6;
			}
		}
	}
}

void LevelSelectMenu::draw()
{
	SDL_RenderCopy(renderer_, backgroundTexture_, NULL, &dest_);
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->draw(renderer_);
	}
}
