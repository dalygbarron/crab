#include "Graphics.hh"
#include <string>
#include <SDL2/SDL.h>


Graphics::Graphics(string title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) throw 1;
    this->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!this->window) throw 2;
    this->screenSurface = SDL_GetWindowSurface(this->window);
    SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(this->window);
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
