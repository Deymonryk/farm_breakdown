#include "Message.h"

Message::Message(SDL_Renderer* renderer, const char* path, std::map<const char*, Button*> buttons, SDL_Rect messageParameters)
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
				gameState = GameState::NEW_GAME;
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
