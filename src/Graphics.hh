#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <SDL2/SDL.h>

/**
 * Used to display graphics on the screen and load images and stuff.
 */
class Graphics
{
    SDL_Window *window;
    SDL_Surface *screenSurface;

public:
    /**
     * Creates the renderer and a game window.
     * @param title is the title of the window.
     * @param width is the width of the window.
     * @param height is the height of the window.
     * @throws int when there is an sdl problem.
     */
    Graphics(string title, int width, int height);

    /**
     * Destroys the renderer and turns off SDL again.
     */
    ~Graphics();
};

#endif
