#include "Scene.h"

void Scene::LoadGameEntities()
{
    LoadBackground("data/22-Breakout-Tiles.png");
    LoadPlatform("data/50-Breakout-Tiles.png", 160, 40);
    //ball start position based on platform position -> should be loaded after platform
    LoadBall("data/58-Breakout-Tiles.png", 40);
    LoadBricks("data/01-Breakout-Tiles.png", 8, 3);
}

void Scene::LoadBackground(const char* path)
{
    //loading background
    sceneBackground_ = TextureManager::loadTexture(path, renderer_);
}

void Scene::LoadPlatform(const char* path, int platformWidth, int platformHeight)
{
    //loading player
    if (platformWidth > 0 && platformHeight > 0)
    {
        SDL_Rect platParam;
        platParam.x = windowWidth_ / 2 - platformWidth / 2;
        platParam.y = windowHeight_ - platformHeight;
        platParam.w = platformWidth;
        platParam.h = platformHeight;
        platform_ = new Platform(path, renderer_, platParam, windowWidth_/36);
    }
    else
    {
        std::cout << "Platform initialization Error: " << SDL_GetError() << "\n";
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

        SDL_Rect ballParam;
        ballParam.x = platformX + platformWidth / 2 - ballDiameter / 2;
        ballParam.y = platformY - ballDiameter;
        ballParam.w = ballParam.h = ballDiameter;

        ball_ = new Ball(path, renderer_, ballParam);
    }
    else
    {
        std::cout << "Ball initialization Error: " << SDL_GetError() << "\n";
        exit(1);
    }

}

void Scene::LoadBricks(const char* path, int verticalNumber, int horizontalNumber)
{
    SDL_Rect brickParam;
    brickParam.w = windowWidth_ / verticalNumber;;
    brickParam.h = (windowHeight_ * 0.4) / horizontalNumber;

    int verticalStartPoint = (windowWidth_ - brickParam.w * verticalNumber) / 2;
    for (int j = 0; j < horizontalNumber; j++)
    {
        std::vector<Brick*> temp;
        for (int i = 0; i < verticalNumber; i++)
        {
            brickParam.x = verticalStartPoint + i * brickParam.w;
            brickParam.y = j * brickParam.h + 1;
            
            Brick* brick = new Brick(path, renderer_, brickParam);
            if (!brick)
            {
                std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                exit(1);
            }
            temp.push_back(brick);
        }
        brickArray_.push_back(temp);
    }
    nActiveBricks_ = verticalNumber * horizontalNumber;
}

void Scene::CheckBorderCollision()
{
    ball_->borderCollision(windowWidth_);
}

void Scene::CheckPlatformCollision()
{
    int platX, platY;
    int platWidth, platHeight;
    platform_->getPosition(platX, platY);
    platform_->getSize(platWidth, platHeight);

    ball_->platformCollision(*platform_);
}

void Scene::CheckBrickCollision()
{
    for (auto raw : brickArray_)
    {
        for (auto brick : raw)
        {
            if (brick->getActivity())
            {
                bool startBrickActivity = brick->getActivity();
                ball_->brickCollision(*brick);
                bool finishBrickActivity = brick->getActivity();
                if (startBrickActivity != finishBrickActivity)
                {
                    nActiveBricks_--;
                }
            }
        }
    }
}

Scene::Scene(SDL_Renderer* renderer, int wWidth, int wHeight)
    : WindowState(renderer), windowWidth_(wWidth), windowHeight_(wHeight)
{
    sceneState_ = SceneState::INACTIVE;
    LoadGameEntities();
}

Scene::~Scene()
{
    SDL_RenderClear(renderer_);
    SDL_DestroyTexture(sceneBackground_);
}

void Scene::update()
{
    if (sceneState_ == SceneState::ACTIVE)
    {
        ball_->Update();

        if (ball_->isGameOver(windowHeight_))
        {
            sceneState_ = SceneState::DEFEAT;
        }
        CheckBorderCollision();
        CheckPlatformCollision();
        CheckBrickCollision();
    }
}

void Scene::draw()
{
    SDL_RenderCopy(renderer_, sceneBackground_, NULL, NULL);
    for (int i = 0; i < brickArray_.size(); i++)
    {
        for (int j = 0; j < brickArray_[i].size(); j++)
        {
            brickArray_[i][j]->Draw();
        }
    }
    platform_->Draw();
    ball_->Draw();
}

void Scene::handleInput(SDL_Event& e, GameState& gameState)
{
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
        case SDLK_LEFT:
            movePlatformLeft();
            break;
        case SDLK_RIGHT:
            movePlatformRight();
            break;
        default:
            break;
        }
    }
}

void Scene::movePlatformLeft()
{
    int platX, platY;
    int platXSpeed, platYSpeed;
    platform_->getPosition(platX, platY);
    platform_->getSpeed(platXSpeed, platYSpeed);

    platX -= platXSpeed;

    if (sceneState_ == SceneState::INACTIVE)
    {
        int ballX, ballY;
        ball_->getPosition(ballX, ballY);
        ball_->setPosition(ballX - platXSpeed, ballY);
        if (platX < 0)
        {
            int ballDiameter;
            ball_->getSize(ballDiameter, ballDiameter);
            int platWidth, platHeight;
            platform_->getSize(platWidth, platHeight);
            ball_->setPosition(platWidth / 2 - ballDiameter / 2, ballY);
        }
    }
    if (platX < 0)
    {
        platX = 0;
    }
    platform_->setPosition(platX, platY);
}

void Scene::movePlatformRight()
{
    int platX, platY;
    int platW, platH;
    int platXSpeed, platYSpeed;
    platform_->getPosition(platX, platY);
    platform_->getSpeed(platXSpeed, platYSpeed);
    platform_->getSize(platW, platH);

    platX += platXSpeed;
    if (sceneState_ == SceneState::INACTIVE)
    {
        int ballX, ballY;
        ball_->getPosition(ballX, ballY);
        ball_->setPosition(ballX + platXSpeed, ballY);
        if (platX + platW > windowWidth_)
        {
            int ballDiameter;
            ball_->getSize(ballDiameter, ballDiameter);
            int platWidth, platHeight;
            platform_->getSize(platWidth, platHeight);

            ball_->setPosition(platX + platWidth / 2 - ballDiameter / 2 - platXSpeed, ballY);
        }
    }
    if (platX + platW > windowWidth_)
    {
        platX = windowWidth_ - platW;
    }
    platform_->setPosition(platX, platY);
}

void Scene::loadGame(int mouseX, int mouseY)
{
    int ballX, ballY;
    int ballDiameter;
    ball_->getPosition(ballX, ballY);
    ball_->getSize(ballDiameter, ballDiameter);
  
    if (mouseY < ballY + ballDiameter / 2)
    {
        sceneState_ = SceneState::ACTIVE;

        //making ball center hit the chosen point
        mouseX -= ballDiameter / 4;

        int deltaX = mouseX - ballX;
        int deltaY = mouseY - ballY;
        
        //normalization
        if (abs(deltaX) > abs(deltaY))
        {
            deltaY = -round(10 * deltaY / deltaX);
            deltaX = 10 * (deltaX / abs(deltaX));
        }
        else
        {
            deltaX = -round(10 * deltaX / deltaY);
            deltaY = 10 * (deltaY / abs(deltaY));
        }
        ball_->setSpeed(deltaX, deltaY);
    }
}

bool Scene::isSceneActive()
{
    if (sceneState_ == SceneState::ACTIVE)
    {
        return true;
    }
    return false;
}

bool Scene::isGameOver()
{
    if (sceneState_ == SceneState::DEFEAT)
    {
        return true;
    }
    return false;
}
