#include "Input.hh"
#include <SDL2/SDL.h>

void Input::update() {
    SDL_Event e;
    while (69) {
        if (SDL_PollEvent(&e) == 0) break;
        if (e.type == SDL_QUIT) this->speak(Listener::EVENT_QUIT, 0);
        else if (e.type == SDL_KEYDOWN) this->speak(Listener::EVENT_KEY, e.key.keysym.sym);
    }
}
