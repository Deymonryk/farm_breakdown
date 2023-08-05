#include "LevelGenerator.h"

void LevelGenerator::GenerateLevel1Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
}

void LevelGenerator::GenerateLevel2Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
    std::vector<Brick*> brickArray;
    std::vector<std::string> cornerBrickTexturePathes = { "data/level2/column_corner.png" };
    SDL_Rect leftCornerColumnParam{ 0, 0, 38, 26 };
    Brick* leftCornerColumn = new Brick(cornerBrickTexturePathes, renderer, leftCornerColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightCornerColumnParam{ 720 - 38, 0, 38, 26 };
    Brick* rightCornerColumn = new Brick(cornerBrickTexturePathes, renderer, rightCornerColumnParam, SpriteState::INVULNERABLE);
    if (leftCornerColumn && rightCornerColumn)
    {
        brickArray.push_back(leftCornerColumn);
        brickArray.push_back(rightCornerColumn);
    }

    int backColumnMargin = (windowWidth - leftCornerColumnParam.w) / 3;
    std::vector<std::string> backBrickTexturePathes = { "data/level2/column_back.png" };
    SDL_Rect leftBackColumnParam{ backColumnMargin - 34, 0, 68, 26 };
    Brick* leftBackColumn = new Brick(backBrickTexturePathes, renderer, leftBackColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightBackColumnParam{ backColumnMargin + leftBackColumnParam.x, 0, 68, 26 };
    Brick* rightBackColumn = new Brick(backBrickTexturePathes, renderer, rightBackColumnParam, SpriteState::INVULNERABLE);
    if (leftBackColumn && rightBackColumn)
    {
        brickArray.push_back(leftBackColumn);
        brickArray.push_back(rightBackColumn);
    }

    std::vector<std::string> sideBrickTexturePathes = { "data/level2/column_side.png" };
    SDL_Rect leftSideColumnParam{ 0, windowHeight * 0.5 - 69, 14, 69 };
    Brick* leftSideColumn = new Brick(sideBrickTexturePathes, renderer, leftSideColumnParam, SpriteState::INVULNERABLE);
    SDL_Rect rightSideColumnParam{ windowWidth - 14, windowHeight * 0.5 - 69, 14, 69 };
    Brick* rightSideColumn = new Brick(sideBrickTexturePathes, renderer, rightSideColumnParam, SpriteState::INVULNERABLE);
    if (leftSideColumn && rightSideColumn)
    {
        brickArray.push_back(leftSideColumn);
        brickArray.push_back(rightSideColumn);
    }

    std::vector<std::string> brickTexturePathes = { "data/level2/box_open.png", "data/level2/box_lid.png" };
    std::pair<int, int>brickFieldSize(windowWidth - 14 * 2, windowHeight - 26);

    SDL_Rect brickParam;
    brickParam.w = brickFieldSize.first / 5;
    brickParam.h = (brickFieldSize.second * 0.4) / 3;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            brickParam.x = 14 + i * brickParam.w;
            brickParam.y = 26 + j * brickParam.h + 1;

            Brick* brick = new Brick(brickTexturePathes, renderer, brickParam, SpriteState::TWO_LIVES);
            if (!brick)
            {
                std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                exit(1);
            }
            brickArray.push_back(brick);
        }
    }
    LevelManager::LoadBricksToJSON("gameinfo/level_data/level2", brickArray);
}

void LevelGenerator::GenerateLevel3Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
    std::vector<Brick*> brickArray;

    int startPosition = 3;
    int currentXpos = startPosition;

    //load fence bricks
    //load 3 long fences
    std::vector<std::string> brickLongFenceTexturePathes = { "data/level3/fence2.png", "data/level3/fence_outline2.png" };
    SDL_Rect brickParamLong{ 0, 0, 110, 60 };
    for (int i = 0; i < 3; i++)
    {
        brickParamLong.x = currentXpos;
        Brick* brick = new Brick(brickLongFenceTexturePathes, renderer, brickParamLong, SpriteState::ONE_LIFE, true);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        currentXpos += brickParamLong.w;
        brickArray.push_back(brick);
    }
    //load 1 short fence
    std::vector<std::string> brickShortFenceTexturePathes = { "data/level3/fence1.png", "data/level3/fence_outline1.png" };
    SDL_Rect brickParamShort{ currentXpos, 0, 55, 60 };
    Brick* brick = new Brick(brickShortFenceTexturePathes, renderer, brickParamShort, SpriteState::ONE_LIFE, true);
    if (!brick)
    {
        std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
        exit(1);
    }
    currentXpos += brickParamShort.w;
    brickArray.push_back(brick);

    //load 3 long fences
    for (int i = 0; i < 3; i++)
    {
        brickParamLong.x = currentXpos;
        Brick* brick = new Brick(brickLongFenceTexturePathes, renderer, brickParamLong, SpriteState::ONE_LIFE, true);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        currentXpos += brickParamLong.w;
        brickArray.push_back(brick);
    }

    //load paving bricks
    //load paving between dirt
    int pavingWidth = windowWidth / 13 - 2;
    int margin = pavingWidth + 2;
    SDL_Rect brickParamPaving{ 0, 61, pavingWidth, 51 };
    std::vector<std::string> brickPavingPathes = { "data/level3/paving.png", "data/level3/paving_outline.png" };
    currentXpos = startPosition;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            if (i % 3 == 0)
            {
                brickParamPaving.x = currentXpos;
                Brick* brick = new Brick(brickPavingPathes, renderer, brickParamPaving, SpriteState::ONE_LIFE, true);
                if (!brick)
                {
                    std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                    exit(1);
                }
                brickArray.push_back(brick);
            }
            currentXpos += margin;
        }
        brickParamPaving.y += margin;
        currentXpos = startPosition;
    }
    //load bottom row of paving
    for (int i = 0; i < 13; i++)
    {
        brickParamPaving.x = currentXpos;
        Brick* brick = new Brick(brickPavingPathes, renderer, brickParamPaving, SpriteState::ONE_LIFE, true);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        brickArray.push_back(brick);
        currentXpos += margin;
    }
    LevelManager::LoadBricksToJSON("gameinfo/level_data/level3", brickArray);
}

void LevelGenerator::GenerateLevel4Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
    std::vector<Brick*> brickArray;
    int startXPosition = 59;
    int startYPosition = 62;

    int currentXpos = startXPosition;
    int currentYpos = startYPosition;
    std::vector<std::string> brickPathes = { "data/level4/brick.png" };
    SDL_Rect brickParameters{ currentXpos, currentYpos, 45, 46 };
    int marginBetweenPads = 10;
    int marginThroughPaving = 69;
    for (int i = 0; i < 3; i++)
    {
        brickParameters.y = currentYpos;
        for (int j = 0; j < 11; j++)
        {
            if (j % 3 != 2)
            {
                brickParameters.x = currentXpos;
                Brick* brick = new Brick(brickPathes, renderer, brickParameters, SpriteState::ONE_LIFE);
                if (!brick)
                {
                    std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
                    exit(1);
                }
                brickArray.push_back(brick);
                if (j % 3 == 0)
                {
                    currentXpos += marginBetweenPads + brickParameters.w;
                }
                else if (j % 3 == 1)
                {
                    currentXpos += marginThroughPaving + brickParameters.w;
                }
            }
        }
        currentXpos = startXPosition;
        currentYpos += 52;
    }

    LevelManager::LoadBricksToJSON("gameinfo/level_data/level4bricks.json", brickArray);
}

void LevelGenerator::GenerateLevel5Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
}

void LevelGenerator::GenerateLevel6Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
}
