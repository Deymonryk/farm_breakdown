#include "Scene.h"

void Scene::LoadGameEntities(GameLevels loadedLevel)
{
    switch (loadedLevel)
    {
    case GameLevels::Level1:
        LoadLevel1();
        break;
    case GameLevels::Level2:
        LoadLevel2();
        break;
    case GameLevels::Level3:
        LoadLevel3();
        break;
    case GameLevels::Level4:
        LoadLevel4();
        break;
    case GameLevels::Level5:
        LoadLevel5();
        break;
    case GameLevels::Level6:
        LoadLevel6();
        break;
    default:
        break;
    }
}

void Scene::LoadLevel1()
{
    LoadBackground("data/background.png");  
    LoadPlatform( 160, 40);

    //ball start position based on platform position -> should be loaded after platform
    std::vector<std::string> ballTexturePathes = { "data/58-Breakout-Tiles.png" };
    LoadBall(ballTexturePathes, 40);

    std::vector<std::string> brickTexturePathes = { "data/01-Breakout-Tiles.png" };
    SDL_Rect brickParam;
    brickParam.w = windowWidth_ / 5;
    brickParam.h = (windowHeight_ * 0.4) / 3;
    std::ofstream file("gameinfo/level_data/level1.json");
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            brickParam.x = i * brickParam.w;
            brickParam.y = j * brickParam.h + 1;

            Brick* brick = new Brick(brickTexturePathes, renderer_, brickParam, SpriteState::ONE_LIFE);
            if (!brick)
            {
                std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                exit(1);
            }
            brickArray_.push_back(brick);
        }
    }
    nActiveBricks_ = 15;
}

void Scene::LoadLevel2()
{
    LoadBackground("data/background.png");
    std::vector<std::string> platformTexturePathes = { "data/50-Breakout-Tiles.png" };
    LoadLevelFromJSON("level2");

    LoadPlatform( 160, 40);
    //ball start position based on platform position -> should be loaded after platform
    /*std::vector<std::string> ballTexturePathes = { "data/58-Breakout-Tiles.png" };
    LoadBall(ballTexturePathes, 40);

    loadLevel2Environment();
    loadLevel2Bricks();*/
}

void Scene::loadLevel2Environment()
{
    std::vector<std::string> cornerBrickTexturePathes = { "data/column_corner.png" };
    SDL_Rect leftCornerColumnParam{ 0, 0, 38, 26 };
    Brick* leftCornerColumn = new Brick(cornerBrickTexturePathes, renderer_, leftCornerColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightCornerColumnParam{ windowWidth_ - 38, 0, 38, 26 };
    Brick* rightCornerColumn = new Brick(cornerBrickTexturePathes, renderer_, rightCornerColumnParam, SpriteState::INVULNERABLE);
    if (leftCornerColumn && rightCornerColumn)
    {
        brickArray_.push_back(leftCornerColumn);
        brickArray_.push_back(rightCornerColumn);
    }

    int backColumnMargin = (windowWidth_ - leftCornerColumnParam.w) / 3;
    std::vector<std::string> backBrickTexturePathes = { "data/column_back.png" };
    SDL_Rect leftBackColumnParam{ backColumnMargin - 34, 0, 68, 26 };
    Brick* leftBackColumn = new Brick(backBrickTexturePathes, renderer_, leftBackColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightBackColumnParam{ backColumnMargin + leftBackColumnParam.x, 0, 68, 26 };
    Brick* rightBackColumn = new Brick(backBrickTexturePathes, renderer_, rightBackColumnParam, SpriteState::INVULNERABLE);
    if(leftBackColumn&& rightBackColumn)
    {
        brickArray_.push_back(leftBackColumn);
        brickArray_.push_back(rightBackColumn);
    }

    std::vector<std::string> sideBrickTexturePathes = { "data/column_side.png" };
    SDL_Rect leftSideColumnParam{ 0, windowHeight_ * 0.5 - 69, 14, 69 };
    Brick* leftSideColumn = new Brick(sideBrickTexturePathes, renderer_, leftSideColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightSideColumnParam{ windowWidth_ - 14, windowHeight_ * 0.5 - 69, 14, 69 };
    Brick* rightSideColumn = new Brick(sideBrickTexturePathes, renderer_, rightSideColumnParam, SpriteState::INVULNERABLE);
    if(leftSideColumn&& rightSideColumn)
    {
        brickArray_.push_back(leftSideColumn);
        brickArray_.push_back(rightSideColumn);
    }
}

void Scene::loadLevel2Bricks()
{
    std::vector<std::string> brickTexturePathes = { "data/box_open.png", "data/box_lid.png" };
    std::pair<int, int>brickFieldSize(windowWidth_ - 14 * 2, windowHeight_ - 26);

    SDL_Rect brickParam;
    brickParam.w = brickFieldSize.first / 5;
    brickParam.h = (brickFieldSize.second * 0.4) / 3;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            brickParam.x = 14 + i * brickParam.w;
            brickParam.y = 26 + j * brickParam.h + 1;

            Brick* brick = new Brick(brickTexturePathes, renderer_, brickParam, SpriteState::TWO_LIVES);
            if (!brick)
            {
                std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                exit(1);
            }
            brickArray_.push_back(brick);
        }
    }
}

void Scene::LoadLevel3()
{
    LoadBackground("data/planting_background.png");
    LoadLevelFromJSON("level3");
    /*
    LoadPlatform(160, 40); 
    std::vector<std::string> ballTexturePathes = { "data/58-Breakout-Tiles.png" };
    LoadBall(ballTexturePathes, 40);

    int startPosition = 3;
    int currentXpos = startPosition;

    //load fence bricks
    LoadLevel3LongFences(3, currentXpos);
    std::vector<std::string> brickShortFenceTexturePathes = { "data/fence1.png", "data/fence_outline1.png" };
    SDL_Rect brickParamShort{ currentXpos, 0, 55, 60 };
    Brick* brick = new Brick(brickShortFenceTexturePathes, renderer_, brickParamShort, SpriteState::ONE_LIFE, true);
    if (!brick)
    {
        std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
        exit(1);
    }
    currentXpos += brickParamShort.w;
    nActiveBricks_++;
    brickArray_.push_back(brick);
    LoadLevel3LongFences(3, currentXpos);
    
    //load paving bricks
    int pavingWidth = windowWidth_ / 13 - 2;
    int margin = pavingWidth + 2;
    SDL_Rect brickParamPaving{ 0, 61, pavingWidth, 51 };
    std::vector<std::string> brickPavingPathes = { "data/paving.png", "data/paving_outline.png" };
    currentXpos = startPosition;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            if(i%3==0)
            {
                brickParamPaving.x = currentXpos;
                Brick* brick = new Brick(brickPavingPathes, renderer_, brickParamPaving, SpriteState::ONE_LIFE, true);
                if (!brick)
                {
                    std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                    exit(1);
                }
                nActiveBricks_++;
                brickArray_.push_back(brick);
            }
            currentXpos += margin;
        }
        brickParamPaving.y += margin;
        currentXpos = startPosition;
    }
    for (int i = 0; i < 13; i++)
    {
        brickParamPaving.x = currentXpos;
        Brick* brick = new Brick(brickPavingPathes, renderer_, brickParamPaving, SpriteState::ONE_LIFE, true);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        nActiveBricks_++;
        brickArray_.push_back(brick);
        currentXpos += margin;
    }
    SaveLevelToJSON("level3");
    */
}

void Scene::LoadLevel3LongFences(int nBricks, int &currentX)
{
    std::vector<std::string> brickLongFenceTexturePathes = { "data/fence2.png", "data/fence_outline2.png" };
    SDL_Rect brickParamLong{ 0, 0, 110, 60 };
    for (int i = 0; i < nBricks; i++)
    {
        brickParamLong.x = currentX;
        Brick* brick = new Brick(brickLongFenceTexturePathes, renderer_, brickParamLong, SpriteState::ONE_LIFE, true);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        currentX += brickParamLong.w;
        nActiveBricks_++;
        brickArray_.push_back(brick);
    }
}

void Scene::LoadLevel4()
{
}

void Scene::LoadLevel5()
{
}

void Scene::LoadLevel6()
{
}

void Scene::LoadBackground(std::string path)
{
    //loading background
    sceneBackground_ = TextureManager::loadTexture(path, renderer_);
}

void Scene::LoadPlatform(int platformWidth, int platformHeight)
{
    std::vector<std::string> platformTexturePathes = { "data/50-Breakout-Tiles.png", "data/51-Breakout-Tiles.png", "data/52-Breakout-Tiles.png" };
    //loading player
    if (platformWidth > 0 && platformHeight > 0)
    {
        SDL_Rect platParam;
        platParam.x = windowWidth_ / 2 - platformWidth / 2;
        platParam.y = windowHeight_ - platformHeight;
        platParam.w = platformWidth;
        platParam.h = platformHeight;
        platform_ = std::make_unique <Platform>(platformTexturePathes, renderer_, platParam, windowWidth_/36);
    }
    else
    {
        std::cout << "Platform initialization Error: " << SDL_GetError() << "\n";
        exit(1);
    }
}

void Scene::LoadBall(std::vector<std::string> path, int ballDiameter)
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

        ball_ = std::make_unique<Ball>(path, renderer_, ballParam);
    }
    else
    {
        std::cout << "Ball initialization Error: " << SDL_GetError() << "\n";
        exit(1);
    }
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
    for (auto brick : brickArray_)
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

void Scene::SaveLevelToJSON(std::string levelName)
{
    std::string savesLocation = "gameinfo/level_data/";

    std::string platformFilePath = savesLocation + levelName + "platform.json";
    LevelManager::LoadPlatformToJSON(platformFilePath, platform_);

    std::string ballFilePath = savesLocation + levelName + "ball.json";
    LevelManager::LoadBallToJSON(ballFilePath, ball_);

    std::string bricksFilePath = savesLocation + levelName + "bricks.json";
    LevelManager::LoadBricksToJSON(bricksFilePath, brickArray_);
}

void Scene::LoadLevelFromJSON(std::string levelName)
{
    std::string savesLocation = "gameinfo/level_data/";

    std::string platformFilePath = savesLocation + levelName + "platform.json";
    platform_ = LevelManager::LoadPlatformFromJSON(platformFilePath, renderer_);

    std::string ballFilePath = savesLocation + levelName + "ball.json";
    ball_ = LevelManager::LoadBallFromJSON(ballFilePath, renderer_);

    std::string bricksFilePath = savesLocation + levelName + "bricks.json";
    brickArray_ = LevelManager::LoadBricksFromJSON(bricksFilePath, renderer_, nActiveBricks_);
}

Scene::Scene(SDL_Renderer* renderer, int wWidth, int wHeight, GameLevels selectedLevel)
    : WindowState(renderer), windowWidth_(wWidth), windowHeight_(wHeight)
{
    sceneState_ = SceneState::INACTIVE;
    LoadGameEntities(selectedLevel);
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

        platform_->Update();
    }
}

void Scene::draw()
{
    SDL_RenderCopy(renderer_, sceneBackground_, NULL, NULL);
    for (int i = 0; i < brickArray_.size(); i++)
    {
        brickArray_[i]->Draw();
    }
    ball_->Draw();
    platform_->Draw();
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
