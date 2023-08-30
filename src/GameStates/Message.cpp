#include "Message.h"

Message::Message(SDL_Renderer* renderer, std::string path, std::map<std::string, Button*> buttons, SDL_Rect messageParameters)
	:WindowState(renderer), buttons_(buttons), dest_(messageParameters)
{
	backgroundTexture_ = TextureManager::loadTexture(path, renderer_);
}

void Message::update()
{

}

void Message::handleInput(SDL_Event& e, GameState& gameState)
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->isHovered(mouseX, mouseY);
		if (it->second->getHovered() && e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (it->first == "restart")
			{
				gameState = GameState::RELOAD_LEVEL;
			}
			else if (it->first == "menu")
			{
				gameState = GameState::MAIN_MENU;
			}
			else if (it->first == "resume")
			{
				gameState = GameState::SCENE;
			}
			else if (it->first == "nextLevel")
			{
				gameState = GameState::NEXT_LEVEL;
			}
		}
	}
}

void Message::handleInput(SDL_Event& e, GameState& gameState, GameLevels& currentLevel)
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->isHovered(mouseX, mouseY);
		if (it->second->getHovered() && e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (it->first == "restart")
			{
				gameState = GameState::RELOAD_LEVEL;
			}
			else if (it->first == "menu")
			{
				gameState = GameState::MAIN_MENU;
			}
			else if (it->first == "resume")
			{
				gameState = GameState::SCENE;
			}
			
		}
	}
}

void Message::draw()
{
	SDL_RenderCopy(renderer_, backgroundTexture_, NULL, &dest_);
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		it->second->draw(renderer_);
	}
}

bool Message::isButtonPressed(std::string buttonName, int x, int y)
{
	for (auto it = buttons_.begin(); it != buttons_.end(); ++it)
	{
		if (it->first == buttonName && it->second->getHovered())
		{
			return true;
		}
	}
	
	return false;
}
