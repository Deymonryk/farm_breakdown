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
    scene_ = new Scene(renderer_, width_, height_);
    if (!scene_)
    {
        std::cout << "Failed to load scene\n";
        isRunning_ = false;
        exit(1);
    }
}


Window::Window(int width, int height, bool isFullscreen) :
    width_(width),
    height_(height)
{
    CreateWindow(isFullscreen);
    CreateRenderer();
   
    loadScene();
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
    
    switch (e.type)
    {
        case SDL_QUIT:
            isRunning_ = false;
            break;
        default:
            break;
    }

    SDL_UpdateWindowSurface(window_);
}

void Window::UpdateWindow()
{
    scene_->Update();
}

void Window::Draw()
{
    SDL_RenderClear(renderer_);

    scene_->Draw();

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
