#include "Graphics.hh"
#include <string>
#include <iostream>
#include <SDL2/SDL.h>


Graphics::Graphics(std::string *title, int width, int height, std::string *tileset)
{
    // Start sdl and stuff.
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    this->window = SDL_CreateWindow(
        title->c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!this->window)
    {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    this->screen = SDL_GetWindowSurface(this->window);
    // Load the tilset.
	SDL_Surface* loadedSurface = SDL_LoadBMP(tileset->c_str());
	if(!loadedSurface)
	{
		std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
	}
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
    this->tileset = SDL_ConvertSurface(loadedSurface, this->screen->format, NULL);
    if (!this->tileset)
    {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
	SDL_FreeSurface(loadedSurface);
    // Set up the tiling rectangles.
    this->srcRect.w = this->tileset->w / 16;
    this->srcRect.h = this->tileset->h / 16;
    this->dstRect.x = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
    // Clear the background to start.
    this->flush(0xf00faa);
    this->frame();
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->window);
    SDL_FreeSurface(this->tileset);
    SDL_Quit();
}

void Graphics::blitTile(int tile, int x, int y, int fg, int bg)
{
    this->srcRect.x = (tile % 16) * this->srcRect.w;
    this->srcRect.y = tile / 16 * this->srcRect.h;
    this->dstRect.x = x * this->dstRect.w;
    this->dstRect.y = y * this->dstRect.h;
    SDL_BlitSurface(this->tileset, &this->srcRect, this->screen, &this->dstRect);
}

void Graphics::flush(int colour)
{
    unsigned char r = (colour >> 4) & 0xff;
    unsigned char g = (colour >> 2) & 0xff;
    unsigned char b = colour & 0xff;
    SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, r, g, b));
}

void Graphics::frame()
{
    SDL_UpdateWindowSurface(this->window);
}
