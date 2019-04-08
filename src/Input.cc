#include "Input.hh"
#include <SDL2/SDL.h>
#include "Observer.hh"

void Input::update() {
    SDL_Event e;
    while (69) {
        if (SDL_PollEvent(&e) == 0) break;
        if (e.type == SDL_QUIT) Speaker::speak(this, Speaker::EVENT_QUIT, 0);
        else if (e.type == SDL_KEYDOWN) Speaker::speak(this, Speaker::EVENT_KEY, e.key.keysym.sym);
    }
}
