#include "Scene.h"

void Scene::LoadBackground(const char* path)
{
    //loading background
    sceneBackground_ = TextureManager::loadTexture(path, renderer_);
}

void Scene::LoadGameEntities()
{
    LoadBackground("data/22-Breakout-Tiles.png");
    LoadPlatform("data/50-Breakout-Tiles.png", 160, 40);
    //ball start position based on platform position -> should be loaded after platform
    LoadBall("data/58-Breakout-Tiles.png", 40);
}

void Scene::LoadPlatform(const char* path, int platformWidth, int platformHeight)
{
    //loading player
    if (platformWidth > 0 && platformHeight > 0)
    {
        platform_ = new Platform(path, renderer_,
            std::make_pair(windowWidth_ / 2, windowHeight_ - platformHeight), std::make_pair(platformWidth, platformHeight));
    }
    else
    {
        std::cout << "Platform initialization Error: " << SDL_GetError() << "\n";
        isSceneActie = false;
        exit(1);
    }
}

void Scene::LoadBall(const char* path, int ballDiameter)
{
    if (ballDiameter > 0)
    {
        int platformX, platformY;
        int platformWidth, platformHeight;
        platform_->getPosition(platformX, platformY);
        platform_->getSize(platformWidth, platformHeight);

        int ballX = platformX + platformWidth / 2 - ballDiameter / 2;
        int ballY = platformY - ballDiameter;
        ball_ = new Ball(path, renderer_, std::make_pair(ballX, ballY), ballDiameter);
    }
    else
    {
        std::cout << "Ball initialization Error: " << SDL_GetError() << "\n";
        isSceneActie = false;
        exit(1);
    }

}

Scene::Scene(SDL_Renderer* ren, int wWidth, int wHeight)
    :windowWidth_(wWidth), windowHeight_(wHeight), renderer_(ren)
{
    LoadGameEntities();
}

Scene::~Scene()
{
    SDL_RenderClear(renderer_);
    SDL_DestroyTexture(sceneBackground_);
}

void Scene::Update()
{
}

void Scene::Draw()
{
    SDL_RenderCopy(renderer_, sceneBackground_, NULL, NULL);
    platform_->Draw();
    ball_->Draw();
}
