#include "Graphics.hh"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TILESET_FILE "bing.png"
#define TILE_COUNT 16

const Colour Colour::RED = Colour(255, 0, 0);

const Colour Colour::MAROON = Colour(100, 0, 10);

const Colour Colour::GREEN = Colour(0, 255, 0);

const Colour Colour::BLUE = Colour(0, 0, 255);

const Colour Colour::NAVY = Colour(0, 0, 32);

const Colour Colour::YELLOW = Colour(255, 255, 0);

const Colour Colour::ORANGE = Colour(255, 200, 0);

const Colour Colour::CYAN = Colour(0, 255, 255);

const Colour Colour::MAGENTA = Colour(255, 0, 255);

const Colour Colour::BLACK = Colour(0, 0, 0);

const Colour Colour::DARK_GREY = Colour(20, 20, 20);

const Colour Colour::GREY = Colour(100, 100, 100);

const Colour Colour::LIGHT_GREY = Colour(200, 200, 200);

const Colour Colour::WHITE = Colour(255, 255, 255);

Colour::Colour() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

Colour::Colour(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Colour::Colour(int values) {
    this->red = (values >> 16) & 0xff;
    this->green = (values >> 8) & 0xff;
    this->blue = values & 0xff;
}

Colour Colour::operator+(Colour other) const {
    int r = this->red + other.red;
    int g = this->green + other.green;
    int b = this->blue + other.blue;
    return Colour(
        (r > 255) ? 255 : r,
        (g > 255) ? 255 : g,
        (b > 255) ? 255 : b
    );
}

Colour Colour::operator-(Colour other) const {
    return Colour(this->red - other.red, this->green - other.green, this->blue - other.blue);
}

Colour Colour::operator*(Colour other) const {
    float r = this->red / 255.0f * other.red / 255.0f;
    float g = this->green / 255.0f * other.green / 255.0f;
    float b = this->blue / 255.0f * other.blue / 255.0f;
    return Colour((unsigned char)(r * 255), (unsigned char)(g * 255), (unsigned char)(b * 255));
}

Colour Colour::operator/(Colour other) const {
    return Colour(this->red / other.red, this->green / other.green, this->blue / other.blue);
}

Colour Colour::operator*(float other) const {
    float r = this->red * other;
    float g = this->green * other;
    float b = this->blue * other;
    return Colour(
        (r > 255) ? 255 : (unsigned char)r,
        (g > 255) ? 255 : (unsigned char)g,
        (b > 255) ? 255 : (unsigned char)b
    );

}

Colour Colour::operator/(float other) const {
    return Colour(this->red / other, this->green / other, this->blue / other);
}

Graphics::Graphics(char const *title, Position dimensions, int fullscreen): dimensions(dimensions) {
    // Start sdl and stuff.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
    // Load the tilset.
	SDL_Surface* loadedSurface = IMG_Load(TILESET_FILE);
	if(!loadedSurface) {
		std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
	}
    // make window.
    this->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        dimensions.x * loadedSurface->w / TILE_COUNT,
        dimensions.y * loadedSurface->h / TILE_COUNT,
        SDL_WINDOW_SHOWN | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0)
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
    this->tileset = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
    if (!this->tileset) {
        std::cout << "sdl: " << SDL_GetError() << std::endl;
        throw 1;
    }
	SDL_FreeSurface(loadedSurface);
    // Turn off vsync.
    // Set up the tiling rectangles.
    SDL_QueryTexture(this->tileset, 0, 0, &this->srcRect.w, &this->srcRect.h);
    this->srcRect.w /= TILE_COUNT;
    this->srcRect.h /= TILE_COUNT;
    this->dstRect.w = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
    // Clear the background to start.
    this->flush(Colour::BLACK);
    this->frame();
}

Graphics::~Graphics() {
    SDL_DestroyTexture(this->tileset);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Graphics::blitTile(unsigned char tile, Position pos, Colour fg,  Colour bg) {
    this->srcRect.x = (tile % 16) * this->srcRect.w;
    this->srcRect.y = tile / 16 * this->srcRect.h;
    this->dstRect.x = pos.x * this->dstRect.w;
    this->dstRect.y = pos.y * this->dstRect.h;
    this->flush(bg, &this->dstRect);
    SDL_SetTextureColorMod(this->tileset, fg.red, fg.green, fg.blue);
    SDL_RenderCopy(this->renderer, this->tileset, &this->srcRect, &this->dstRect);
}

void Graphics::blitBox(Rect box,  Colour colour) {
    this->dstRect.x = box.pos.x * this->dstRect.w;
    this->dstRect.y = box.pos.y * this->dstRect.h;
    this->dstRect.w *= box.size.x;
    this->dstRect.h *= box.size.y;
    this->flush(colour, &this->dstRect);
    // Put dstRect back to normal size.
    this->dstRect.w = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
}

void Graphics::blitCharacter(unsigned char c, Position pos,  Colour colour) {
    this->srcRect.x = (c % 16) * this->srcRect.w;
    this->srcRect.y = c / 16 * this->srcRect.h;
    this->dstRect.x = pos.x * this->dstRect.w;
    this->dstRect.y = pos.y * this->dstRect.h;
    SDL_SetTextureColorMod(this->tileset, colour.red, colour.green, colour.blue);
    SDL_RenderCopy(this->renderer, this->tileset, &this->srcRect, &this->dstRect);
}

void Graphics::blitString(char const *text, Position pos,  Colour colour) {
    int offset = 0;
    for (int i = 0; text[i]; i++) {
        // Managing special characters.
        if (text[i] == '@') {
            char type = text[i + 1];
            if (type == '@') {
                this->blitCharacter('@', pos + Position(offset, 0), colour);
                i++;
            } else if (type == 'i') {
                this->blitCharacter(text[i + 2], pos + Position(offset, 0), Colour::RED);
                i += 2;
            }
        } else {
            // displaying normal text.
            this->blitCharacter(text[i], pos + Position(offset, 0), colour);
        }
        offset++;
    }
}

void Graphics::flush(Colour colour, SDL_Rect *rect) {
    SDL_SetRenderDrawColor(this->renderer, colour.red, colour.green, colour.blue, 0xFF);
    if (rect) SDL_RenderFillRect(this->renderer, rect);
    else SDL_RenderClear(this->renderer);
}

void Graphics::flushGradient(Colour top, Colour bottom) {
    // TODO: fix.
    flush(Colour::GREEN, 0);
}

void Graphics::frame() {
    SDL_RenderPresent(this->renderer);
}
