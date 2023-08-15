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
    GenerateFarmFences(renderer, brickArray);

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
    std::vector<Brick*> brickArray;
    int currentX = 0;
    int constructionHeight = 27;
    std::vector<std::string> construction1Pathes = { "data/level5/construction1_fixed.png", "data/level5/construction1_destroyed.png" };
    SDL_Rect construction1Parameters = { currentX, constructionHeight, 147, 199};
    Brick* construction1 = new Brick(construction1Pathes, renderer, construction1Parameters, SpriteState::ONE_LIFE, true);
    brickArray.push_back(construction1);
    currentX += construction1Parameters.w;

    std::vector<std::string> construction2Pathes = { "data/level5/construction2_fixed.png", "data/level5/construction2_destroyed.png" };
    SDL_Rect construction2Parameters = { currentX, constructionHeight, 141, 199 };
    Brick* construction2 = new Brick(construction2Pathes, renderer, construction2Parameters, SpriteState::ONE_LIFE, true);
    brickArray.push_back(construction2);
    currentX += construction2Parameters.w;

    std::vector<std::string> construction3Pathes = { "data/level5/construction3_fixed.png", "data/level5/construction3_destroyed.png" };
    SDL_Rect construction3Parameters = { currentX, constructionHeight, 142, 200 };
    Brick* construction3 = new Brick(construction3Pathes, renderer, construction3Parameters, SpriteState::ONE_LIFE, true);
    brickArray.push_back(construction3);
    currentX += construction3Parameters.w;

    std::vector<std::string> construction4Pathes = { "data/level5/construction4_fixed.png", "data/level5/construction4_destroyed.png" };
    SDL_Rect construction4Parameters = { currentX, constructionHeight, 141, 199 };
    Brick* construction4 = new Brick(construction4Pathes, renderer, construction4Parameters, SpriteState::ONE_LIFE, true);
    brickArray.push_back(construction4);
    currentX += construction4Parameters.w;

    std::vector<std::string> construction5Pathes = { "data/level5/construction5_fixed.png", "data/level5/construction5_destroyed.png" };
    SDL_Rect construction5Parameters = { currentX, constructionHeight, 149, 199 };
    Brick* construction5 = new Brick(construction5Pathes, renderer, construction5Parameters, SpriteState::ONE_LIFE, true);
    brickArray.push_back(construction5);

    std::vector<std::string> ropePathes = { "data/level5/rope.png"};
    SDL_Rect rope1Parameters = { 6, 240, 45, 29 };
    Brick* rope1 = new Brick(ropePathes, renderer, rope1Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(rope1);
    SDL_Rect rope2Parameters = { 54, 233, 45, 29 };
    Brick* rope2 = new Brick(ropePathes, renderer, rope2Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(rope2);

    std::vector<std::string> sackPathes = { "data/level5/sack.png" };
    SDL_Rect sackParameters = { 97, 189, 56, 63 };
    Brick* sack = new Brick(sackPathes, renderer, sackParameters, SpriteState::ONE_LIFE);
    brickArray.push_back(sack);

    std::vector<std::string> lad1Pathes = { "data/level5/lad1.png" };
    SDL_Rect lad1Parameters = { 223, 199, 56, 60 };
    Brick* lad1 = new Brick(lad1Pathes, renderer, lad1Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(lad1);

    std::vector<std::string> lad3Pathes = { "data/level5/lad3.png" };
    SDL_Rect lad3Parameters = { 646, 211, 66, 84 };
    Brick* lad3 = new Brick(lad3Pathes, renderer, lad3Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(lad3);

    std::vector<std::string> lad2Pathes = { "data/level5/lad2.png" };
    SDL_Rect lad2Parameters = { 619, 238, 61, 65 };
    Brick* lad2 = new Brick(lad2Pathes, renderer, lad2Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(lad2);

    std::vector<std::string> girden2Pathes = { "data/level5/girden2.png" };
    SDL_Rect girden2Parameters = { 345, 215, 132, 35 };
    Brick* girden2 = new Brick(girden2Pathes, renderer, girden2Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(girden2);

    std::vector<std::string> girden3Pathes = { "data/level5/girden3.png" };
    SDL_Rect girden3Parameters = { 359, 227, 95, 32 };
    Brick* girden3 = new Brick(girden3Pathes, renderer, girden3Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(girden3);
        
    std::vector<std::string> girden1Pathes = { "data/level5/girden1.png" };
    SDL_Rect girden1Parameters = { 368, 250, 77, 21 };
    Brick* girden1 = new Brick(girden1Pathes, renderer, girden1Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(girden1);
    
    std::vector<std::string> barelPathes = { "data/level5/barel.png" };
    SDL_Rect barelParameters = { 301, 189, 49, 70 };
    Brick* barel = new Brick(barelPathes, renderer, barelParameters, SpriteState::ONE_LIFE);
    brickArray.push_back(barel);

    std::vector<std::string> planksPathes{"data/level5/planks.png"};
    SDL_Rect planks1Parameters = { 521, 235, 51, 28};
    Brick* planks1 = new Brick(planksPathes, renderer, planks1Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(planks1);

    SDL_Rect planks2Parameters = { 570, 237, 51, 28 };
    Brick* planks2 = new Brick(planksPathes, renderer, planks2Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(planks2);

    SDL_Rect planks3Parameters = { 507, 251, 51, 28 };
    Brick* planks3 = new Brick(planksPathes, renderer, planks3Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(planks3);

    SDL_Rect planks4Parameters = { 550, 255, 51, 28 };
    Brick* planks4 = new Brick(planksPathes, renderer, planks4Parameters, SpriteState::ONE_LIFE);
    brickArray.push_back(planks4);

    LevelManager::LoadBricksToJSON("gameinfo/level_data/level5bricks.json", brickArray);
}

void LevelGenerator::GenerateLevel6Bricks(SDL_Renderer* renderer, int windowWidth, int windowHeight)
{
    std::vector<Brick*> brickArray;
    GenerateFarmFences(renderer, brickArray);

    int startXPosition = 60;
    int startYPosition = 50;

    int currentXpos = startXPosition;
    int currentYpos = startYPosition;
    std::vector<std::string> brickPathes = { "data/level6/brick_life1.png", "data/level6/brick_life2.png" };
    SDL_Rect brickParameters{ currentXpos, currentYpos, 42, 57 };
    int marginBetweenPads = 13;
    int marginThroughPaving = 71;
    for (int i = 0; i < 3; i++)
    {
        brickParameters.y = currentYpos;
        for (int j = 0; j < 11; j++)
        {
            if (j % 3 != 2)
            {
                brickParameters.x = currentXpos;
                Brick* brick = new Brick(brickPathes, renderer, brickParameters, SpriteState::TWO_LIVES);
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
    LevelManager::LoadBricksToJSON("gameinfo/level_data/level6bricks.json", brickArray);
}

/** @brief Generates a set of fences placed on the top of the scene
*   Should be used before generating other bricks
*   @return Void.
*/
void LevelGenerator::GenerateFarmFences(SDL_Renderer* renderer, std::vector<Brick*> &brickArray)
{
    //load fence bricks
    //load 3 long fences
    int startPosition = 3;
    int currentXpos = startPosition;

    std::vector<std::string> brickLongFenceTexturePathes = { "data/level3/fence2.png"};
    SDL_Rect brickParamLong{ 0, 0, 110, 60 };
    for (int i = 0; i < 3; i++)
    {
        brickParamLong.x = currentXpos;
        Brick* brick = new Brick(brickLongFenceTexturePathes, renderer, brickParamLong, SpriteState::INVULNERABLE);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        currentXpos += brickParamLong.w;
        brickArray.push_back(brick);
    }
    //load 1 short fence
    std::vector<std::string> brickShortFenceTexturePathes = { "data/level3/fence1.png" };
    SDL_Rect brickParamShort{ currentXpos, 0, 55, 60 };
    Brick* brick = new Brick(brickShortFenceTexturePathes, renderer, brickParamShort, SpriteState::INVULNERABLE);
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
        Brick* brick = new Brick(brickLongFenceTexturePathes, renderer, brickParamLong, SpriteState::INVULNERABLE);
        if (!brick)
        {
            std::cout << "Brick initialization Error: " << SDL_GetError() << "\n";
            exit(1);
        }
        currentXpos += brickParamLong.w;
        brickArray.push_back(brick);
    }
}
