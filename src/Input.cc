#include "Input.hh"
#include <SDL2/SDL.h>
#include "Observer.hh"

#define REPEAT 5

void Input::update() {
    SDL_Event e;
    int i = 0;
    while (i < REPEAT) {
        if (SDL_PollEvent(&e) == 0) {
            i++;
            continue;
        }
        if (e.type == SDL_QUIT) Speaker::speak(this, Speaker::EVENT_QUIT, 0);
        else if (e.type == SDL_KEYDOWN) Speaker::speak(this, Speaker::EVENT_KEY, e.key.keysym.sym);
        return;
    }
}
