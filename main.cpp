#include <iostream>
#include <SDL2/SDL.h>
#include "src/Window.h"

int main(int argc, char* argv[])
{
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    Window *window = new Window(720, 480, false);

    while (window->running())
    {
        frameStart = SDL_GetTicks();

        window->ProcessInputs();
        window->UpdateWindow();
        window->Draw();

        //setting FPS equal to 60
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }
    window->Quit();

	return 0;
}