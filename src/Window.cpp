#include "Window.h"

void Window::CreateWindow(bool isFullscreen)
{
    int flag = 0;
    if (isFullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    //creating window and checking it's correctness
    window_ = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width_, height_, flag);
    isRunning_ = true;

    if (!window_)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        isRunning_ = false;
        exit(1);
    }
}

void Window::CreateRenderer()
{
    //creating renderer and checking it's correctness
    renderer_ = SDL_CreateRenderer(window_, 1, 0);
    if (!renderer_)
    {
        std::cout << "Failed to create the renderer\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        isRunning_ = false;
        exit(1);
    }
}

void Window::loadScene()
{
    scene_ = new Scene(renderer_, width_, height_, selectedLevel_);
    if (!scene_)
    {
        std::cout << "Failed to load scene\n";
        isRunning_ = false;
        exit(1);
    }
}

void Window::loadMenu()
{
    if (!mainMenu_)
    {
        mainMenu_ = new MainMenu(renderer_, width_, height_);
    }
    if (!mainMenu_)
    {
        std::cout << "Failed to load main menu\n";
        isRunning_ = false;
        exit(1);
    }
}

void Window::loadGameoverMessage()
{
    SDL_Rect msgRect;
    msgRect.w = width_ / 2;
    msgRect.h = height_ / 2;
    msgRect.x = width_ / 2 - msgRect.w / 2;
    msgRect.y = height_ / 2 - msgRect.h / 2;

    int horizontalMargin = 40, verticalMargin = 15;
    int buttonsY = msgRect.y + msgRect.h / 2 + verticalMargin;

    int restartX = msgRect.x + msgRect.w / 2 + horizontalMargin / 2;
    Button* restart = new Button("data/interface/restartButtonActive.png", "data/interface/restartButtonInactive.png", renderer_, 
        SDL_Rect{ restartX, buttonsY, 50, 50 });

    int exitX = msgRect.x + msgRect.w / 2 - horizontalMargin / 2 - 50;
    Button* exit = new Button("data/interface/exitButtonActive.png", "data/interface/exitButtonInactive.png", renderer_, 
        SDL_Rect{ exitX, buttonsY, 50, 50 });

    std::map<std::string, Button*> gameverMessageButtons{
        {"restart", restart},
        {"menu", exit}
    };
    gameoverMessage_ = new Message(renderer_, "data/interface/GameOverMessage.png", gameverMessageButtons, msgRect);
}

void Window::loadVictoryMessage()
{
    SDL_Rect msgRect;
    msgRect.w = width_ / 2;
    msgRect.h = height_ / 2;
    msgRect.x = width_ / 2 - msgRect.w / 2;
    msgRect.y = height_ / 2 - msgRect.h / 2;

    int horizontalMargin = 40, verticalMargin = 15;
    int buttonsY = msgRect.y + msgRect.h / 2 + verticalMargin;

    int victoryX = msgRect.x + msgRect.w / 2 + horizontalMargin / 2;
    Button* nextLevel = new Button("data/interface/nextButtonActive.png", "data/interface/nextButtonInactive.png", renderer_,
        SDL_Rect{ victoryX, buttonsY, 50, 50 });

    int exitX = msgRect.x + msgRect.w / 2 - horizontalMargin / 2 - 50;
    Button* exit = new Button("data/interface/exitButtonActive.png", "data/interface/exitButtonInactive.png", renderer_,
        SDL_Rect{ exitX, buttonsY, 50, 50 });

    std::map<std::string, Button*> victoryMessageButtons{
        {"nextLevel", nextLevel},
        {"menu", exit}
    };
    victoryMessage_ = new Message(renderer_, "data/interface/GameVictoryMessage.png", victoryMessageButtons, msgRect);
}

void Window::loadLevelSelectMenu()
{
    SDL_Rect menuRect;
    menuRect.w = width_ / 2;
    menuRect.h = height_ / 2 + 20;
    menuRect.x = width_ / 2 - menuRect.w / 2;
    menuRect.y = height_ / 2 - menuRect.h / 2;

    int horizontalMargin = 60, veticalMargin = 30;
    Button* butLvl1 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin / 2, menuRect.y + veticalMargin * 2 , 60, 60 },
        SDL_Rect{ 0, 0, 139, 139 });
    Button* butLvl2 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin /2 + 60 + horizontalMargin, menuRect.y + veticalMargin * 2 , 60, 60 },
        SDL_Rect{ 140, 0, 139, 139});    
    Button* butLvl3 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin / 2 + (60 + horizontalMargin) * 2, menuRect.y + veticalMargin * 2, 60, 60 },
        SDL_Rect{ 280, 0, 139, 139});    
    Button* butLvl4 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin / 2, menuRect.y + veticalMargin * 5 / 3 + 60 + veticalMargin, 60, 60 },
        SDL_Rect{ 0, 140, 139, 139});    
    Button* butLvl5 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin / 2 + 60 + horizontalMargin, menuRect.y + veticalMargin * 5 / 3 + 60 + veticalMargin, 60, 60 },
        SDL_Rect{ 140, 140, 139, 139});    
    Button* butLvl6 = new Button("data/interface/levelSelectButtonsActive.png", "data/interface/levelSelectButtonsInactive.png", renderer_,
        SDL_Rect{ menuRect.x + horizontalMargin / 2 + (60 + horizontalMargin) * 2, menuRect.y + veticalMargin * 5 / 3 + 60 + veticalMargin, 60, 60 },
        SDL_Rect{ 280, 140, 139, 139 });
    std::map<std::string, Button*> lvlSelectMenuButtons{
       {"Level1", butLvl1},
       {"Level2", butLvl2},
       {"Level3", butLvl3},
       {"Level4", butLvl4},
       {"Level5", butLvl5},
       {"Level6", butLvl6},
    };

    levelSelectMenu_ = new LevelSelectMenu(renderer_, "data/interface/levelSelectMenuBackground.png", lvlSelectMenuButtons, menuRect);
}

   

Window::Window(int width, int height, bool isFullscreen, std::string windowName) :
    width_(width),
    height_(height)
{
    CreateWindow(isFullscreen);
    SDL_SetWindowTitle(window_, windowName.c_str());
    CreateRenderer();

    loadMenu();
    loadLevelSelectMenu();
    loadGameoverMessage();
    loadVictoryMessage();

    gameState_ = GameState::MAIN_MENU;
}

void Window::Quit()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_QUIT;
}

void Window::ProcessInputs()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    
    if (e.type == SDL_QUIT)
    {
        isRunning_ = false;
    }
    switch (gameState_)
    {
    case GameState::MAIN_MENU:
        mainMenu_->handleInput(e, gameState_);
        break;

    case GameState::LEVEL_SELECT_MENU:
        levelSelectMenu_->handleInput(e, gameState_);
        selectedLevel_ = levelSelectMenu_->getSelectedLevel();
        if (gameState_ == GameState::SCENE)
        {
            loadScene();
        }
        break;

    case GameState::SCENE:
        scene_->handleInput(e, gameState_);

        if (!scene_->isSceneActive() && e.type == SDL_MOUSEBUTTONDOWN)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            scene_->loadGame(x, y);
        }
        break;

    case GameState::GAME_OVER_MESSAGE:
        gameoverMessage_->handleInput(e, gameState_);
        break;

    case GameState::VICTORY_MESSAGE:
        victoryMessage_->handleInput(e, gameState_);
        break;

    default:
        break;
    }

    SDL_UpdateWindowSurface(window_);
}

void Window::UpdateWindow()
{
    switch (gameState_)
    {
    case GameState::MAIN_MENU:
        mainMenu_->update();
        break;

    case GameState::LEVEL_SELECT_MENU:
        levelSelectMenu_->update();
        break;

    case GameState::SCENE:
        scene_->update();
        if (scene_->isGameOver())
        {
            gameState_ = GameState::GAME_OVER_MESSAGE;
        }
        if (scene_->getNumActiveBricks() == 0)
        {
            gameState_ = GameState::VICTORY_MESSAGE;
        }
        break;

    case GameState::GAME_OVER_MESSAGE:
        gameoverMessage_->update();
        break;

    case GameState::VICTORY_MESSAGE:
        victoryMessage_->update();
        break;

    case GameState::RELOAD_LEVEL:
        loadScene();
        gameState_ = GameState::SCENE;
        break;

    case GameState::NEXT_LEVEL:
        if (selectedLevel_ != GameLevels::Level6)
        {
            selectedLevel_ = static_cast<GameLevels>(static_cast<int> (selectedLevel_) + 1);
            loadScene();
            gameState_ = GameState::SCENE;
        }
        else
        {
            gameState_ = GameState::MAIN_MENU;
        }
        break;

    default:
        break;
    }
}

void Window::Draw()
{
    SDL_RenderClear(renderer_);

    switch (gameState_)
    {
    case GameState::MAIN_MENU:
        mainMenu_->draw();
        break;
    case GameState::LEVEL_SELECT_MENU:
        mainMenu_->draw();
        levelSelectMenu_->draw();
        break;
    case GameState::SCENE:
        scene_->draw();
        break;
    case GameState::GAME_OVER_MESSAGE:
        scene_->draw();
        gameoverMessage_->draw();
        break;
    case GameState::VICTORY_MESSAGE:
        scene_->draw();
        victoryMessage_->draw();
        break;
    default:
        break;
    }
    SDL_RenderPresent(renderer_);
}

void Window::getSize(int& w, int& h)
{
    w = width_;
    h = height_;
}

Window::~Window()
{
    SDL_RenderClear(renderer_);
    SDL_DestroyWindow(window_);
}
