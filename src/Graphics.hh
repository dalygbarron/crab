#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * Used to display graphics on the screen and load images and stuff.
 */
class Graphics {
    SDL_Window *window;
    SDL_Surface *screen;
    SDL_Renderer *renderer;
    SDL_Texture *tileset;
    SDL_Rect srcRect;
    SDL_Rect dstRect;

public:
    /**
     * Creates the renderer and a game window.
     * @param *title is the title of the window.
     * @param width is the width of the window.
     * @param height is the height of the window.
     * @throws int when there is an sdl problem.
     */
    Graphics(std::string *title, int width, int height, std::string *tileset);

    /**
     * Destroys the renderer and turns off SDL again.
     */
    ~Graphics();

    /**
     * Renders a tile from a tileset to a given spot on the screen.
     * @param tile is the numerical index of the tile to blit.
     * @param x is the x location on the screen to place it.
     * @param y is the y location on the screen toi place it.
     * @param fg is the foreground colour to give the tile.
     * @param bg is the background colour to give the tile.
     */
    void blitTile(int tile, int x, int y, unsigned int fg, unsigned int bg);

    /**
     * Fills a given rect with colour.
     * @param colour is the colour stored as an int 1 byte each colour.
     * @param rect   is the rect to fill or null for whole screen.
     */
    void flush(int colour, SDL_Rect *rect = NULL);

    /**
     * Updates the screen to show what has been blitted on there lately.
     */
    void frame();
};

#endif
