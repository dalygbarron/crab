#include "Graphics.hh"
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Graphics::Graphics(std::string *title, int width, int height, std::string *tileset) {
    // Start sdl and stuff.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    // make window.
    this->window = SDL_CreateWindow(
        title->c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!this->window) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    // make renderer.
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    // turn on fancy pictures.
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    // Load the tilset.
	SDL_Surface* loadedSurface = IMG_Load(tileset->c_str());
	if(!loadedSurface) {
		std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
	}
    this->tileset = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
    if (!this->tileset) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
	SDL_FreeSurface(loadedSurface);
    // Set up the tiling rectangles.
    SDL_QueryTexture(this->tileset, NULL, NULL, &this->srcRect.w, &this->srcRect.h);
    this->srcRect.w /= 16;
    this->srcRect.h /= 16;
    this->dstRect.w = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
    // Clear the background to start.
    this->flush(0xf00faa);
    this->frame();
}

Graphics::~Graphics() {
    SDL_DestroyTexture(this->tileset);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Graphics::blitTile(unsigned char tile, int x, int y, unsigned int fg, unsigned int bg) {
    this->srcRect.x = (tile % 16) * this->srcRect.w;
    this->srcRect.y = tile / 16 * this->srcRect.h;
    this->dstRect.x = x * this->dstRect.w;
    this->dstRect.y = y * this->dstRect.h;
    this->flush(bg, &this->dstRect);
    SDL_SetTextureColorMod(this->tileset, (fg >> 16) & 0xff, (fg >> 8) & 0xff, fg & 0xff);
    SDL_RenderCopy(this->renderer, this->tileset, &this->srcRect, &this->dstRect);
}

void Graphics::blitBox(int x, int y, int w, int h, unsigned int colour) {
    this->dstRect.x = x * this->dstRect.w;
    this->dstRect.y = y * this->dstRect.h;
    this->dstRect.w *= w;
    this->dstRect.h *= h;
    this->flush(colour, &this->dstRect);
    // Put dstRect back to normal size.
    this->dstRect.w = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
}

void Graphics::blitCharacter(unsigned char c, int x, int y, unsigned int colour) {
    this->srcRect.x = (c % 16) * this->srcRect.w;
    this->srcRect.y = c / 16 * this->srcRect.h;
    this->dstRect.x = x * this->dstRect.w;
    this->dstRect.y = y * this->dstRect.h;
    SDL_SetTextureColorMod(this->tileset, (colour >> 16) & 0xff, (colour >> 8) & 0xff, colour & 0xff);
    SDL_RenderCopy(this->renderer, this->tileset, &this->srcRect, &this->dstRect);
}

void Graphics::blitString(std::string *text, int x, int y, unsigned int colour) {
    for (char c: *text) {
        this->blitCharacter(c, x, y, colour);
        x++;
    }
}

void Graphics::flush(int colour, SDL_Rect *rect) {
    unsigned char r = (colour >> 16) & 0xff;
    unsigned char g = (colour >> 8) & 0xff;
    unsigned char b = colour & 0xff;
    SDL_SetRenderDrawColor(this->renderer, r, g, b, 0xFF);
    if (rect) SDL_RenderFillRect(this->renderer, rect);
    else SDL_RenderClear(this->renderer);
}

void Graphics::frame() {
    SDL_RenderPresent(this->renderer);
}
