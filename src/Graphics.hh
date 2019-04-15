#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector.hh"

/**
 * Represents a nice colour for you.
 */
class Colour {
public:
    const static Colour RED;
    const static Colour MAROON;
    const static Colour GREEN;
    const static Colour BLUE;
    const static Colour NAVY;
    const static Colour YELLOW;
    const static Colour ORANGE;
    const static Colour CYAN;
    const static Colour MAGENTA;
    const static Colour BLACK;
    const static Colour DARK_GREY;
    const static Colour GREY;
    const static Colour LIGHT_GREY;
    const static Colour WHITE;

    unsigned char red;
    unsigned char green;
    unsigned char blue;

    /**
     * Creates a black colour.
     */
    Colour();

    /**
     * Creates the colour for you.
     * @param red   is the red component up to 255.
     * @param green is the green component up to 255.
     * @param blue  is the blue component up to 255.
     */
    Colour(unsigned char red, unsigned char green, unsigned char blue);

    /**
     * Creates a colour that is part of the way between two colours.
     * @param top    is the first colour.
     * @param bottom is the second colour.
     * @param pos    is how far between the two with 0 being top and 1 being bottom.
     */
    Colour(Colour top, Colour bottom, float pos);

    /**
     * Adds two colours together bounded at max light.
     * @param other is the second colour to add.
     * @return a new colour which is the sum of both.
     */
    Colour operator+(Colour other) const;

    /**
     * Subtracts one colour from another.
     * @param other is the colour to subtract.
     * @return the result.
     */
    Colour operator-(Colour other) const;

    /**
     * Multiplies two colours together as if their values were between 0 and 1. Like 0 = 0, and 255 = 1.
     * @param other is the other colour to multiply.
     * @return the result of the multiplication.
     */
    Colour operator*(Colour other) const;

    /**
     * Divides the values of one colour by the values of another.
     * @param other is that other.
     * @return the result of the divisiton.
     */
    Colour operator/(Colour other) const;

    /**
     * Multiplies the values of a colour individually by some number.
     * @param other is the numebr to multiply by.
     * @return the result.
     */
    Colour operator*(float other) const;

    /**
     * Divides a colour by an amount.
     * @param other is that amount.
     * @return the result.
     */
    Colour operator/(float other) const;
};

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
    const Position dimensions;

    /**
     * Creates the renderer and a game window.
     * @param title      is the title of the window.
     * @param dimensions is the dimensions of the window in number of tiles.
     * @param fullscreen is true if you want the game in fullscreen.
     * @throws int when there is an sdl problem.
     */
    Graphics(char const *title, Position dimensions, int fullscreen);

    /**
     * Destroys the renderer and turns off SDL again.
     */
    ~Graphics();

    /**
     * Renders a tile from a tileset to a given spot on the screen.
     * @param tile is the numerical index of the tile to blit.
     * @param pos  is the location on screen to blit the tile.
     * @param fg   is the foreground colour to give the tile.
     * @param bg   is the background colour to give the tile.
     */
    void blitTile(unsigned char tile, Position pos, Colour fg, Colour bg);

    /**
     * Draw a box on the screen in tile coordinates.
     * @param box    is the geometry of the box to draw onscreen.
     * @param colour is the colour to draw the box in.
     */
    void blitBox(Rect box, Colour colour);

    /**
     * Draws a single character to the screen with no backgrond.
     * @param c        is the character of choice.
     * @param position is the onscreen location to blit the character.
     * @param colour   is the colour to draw it in.
     */
    void blitCharacter(unsigned char c, Position position, Colour colour);

    /**
     * Writes a piece of text onto the screen unbounded and new lines do cause new lines.
     * @param text     is the text to write.
     * @param position is the location onscreen to start writing the text.
     * @param colour   is the colour of the text.
     */
    void blitString(char const *text, Position position, Colour colour);

    /**
     * Fills a given rect with colour.
     * @param colour is the colour stored as an int 1 byte each colour.
     * @param rect   is the rect to fill or 0 for whole screen.
     */
    void flush(Colour colour, SDL_Rect *rect = 0);

    /**
     * Fills the whole screen with a gradient. TODO: allow rects as well.
     * @param top    is the colour at the top.
     * @param bottom is the colour at the bottom.
     */
    void flushGradient(Colour top, Colour bottom);

    /**
     * Updates the screen to show what has been blitted on there lately.
     */
    void frame();

    void playSong();

    /**
     * Plays a sound effect for your satisfaction.
     */
    void playSound();
};

#endif
