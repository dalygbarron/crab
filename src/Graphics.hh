#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Generator.hh"

/**
 * Used to display graphics on the screen and load images and stuff.
 * Actually, this does more than just graphics, it also controls user input, and I plan to also make
 * it control music and sound effects just for the hell of it.
 *                  .^o ~\ I am le ostritch
 *                 Y /'~) }      _____
 *                 l/  / /    ,-~     ~~--.,_
 *                    ( (    /  ~-._         ^.
 *                     \ "--'--.    "-._       \
 *                      "-.________     ~--.,__ ^.
 *                                \"~r-.,___.-'-. ^.
 *                                 YI    \\      ~-.\
 *                                 ||     \\        `\
 *                                 ||     //
 *                                 ||    //
 *                                 ||  //
 *                                 || ( c
 *                    ___._ __  ___I|__`--__._ __  _
 *                  "~     ~  "~   ::  ~~"    ~  ~~
 */
class Graphics {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *tileset;
    SDL_Rect srcRect;
    SDL_Rect dstRect;

public:
    const static int RED = 0xff0000;
    const static int MAROON = 0xa00014;
    const static int GREEN = 0xff00;
    const static int BLUE = 0xff;
    const static int NAVY = 0x20;
    const static int YELLOW = 0xffff00;
    const static int ORANGE = 0xfab200;
    const static int CYAN = 0xffff;
    const static int MAGENTA = 0xff00ff;
    const static int BLACK = 0;
    const static int DARK_GREY = 0x111111;
    const static int GREY = 0x555555;
    const static int LIGHT_GREY = 0xbbbbbb;
    const static int WHITE = 0xffffff;

    const int width;
    const int height;
    Generator generator;

    /**
     * Creates the renderer and a game window.
     * @param title      is the title of the window.
     * @param width      is the width of the window.
     * @param height     is the height of the window.
     * @param fullscreen is true if you want the game in fullscreen.
     * @throws int when there is an sdl problem.
     */
    Graphics(char const *title, int width, int height, int fullscreen);

    /**
     * Destroys the renderer and turns off SDL again.
     */
    ~Graphics();

    /**
     * Renders a tile from a tileset to a given spot on the screen.
     * @param tile is the numerical index of the tile to blit.
     * @param x    is the x location in tile coordinates on the screen to place it.
     * @param y    is the y location in tile coordinates on the screen toi place it.
     * @param fg   is the foreground colour to give the tile.
     * @param bg   is the background colour to give the tile.
     */
    void blitTile(unsigned char tile, int x, int y, unsigned int fg, unsigned int bg);

    /**
     * Draw a box on the screen in tile coordinates.
     * @param x      is the left side of the box location in tile coordinates.
     * @param y      is the top side of the box location in tile coordinates.
     * @param w      is the width of the box in tile coordinates.
     * @param h      is the height of the box in tile coordinates.
     * @param colour is the colour to draw the box in.
     */
    void blitBox(int x, int y, int w, int h, unsigned int colour);

    /**
     * Draws a single character to the screen with no backgrond.
     * @param c      is the character of choice.
     * @param x      is the left tile position.
     * @param y      is the top tile position.
     * @param colour is the colour to draw it in.
     */
    void blitCharacter(unsigned char c, int x, int y, unsigned int colour);

    /**
     * Writes a piece of text onto the screen unbounded and new lines do cause new lines.
     * @param text   is the text to write.
     * @param x      is the left start of the text.
     * @param y      is the top start of the text.
     * @param colour is the colour of the text.
     */
    void blitString(char const *text, int x, int y, unsigned int colour);

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
