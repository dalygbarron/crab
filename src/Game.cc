#include "Game.hh"
#include "Content.hh"
#include <iostream>
#include <SDL2/SDL.h>
#include "scenes/Title.hh"

void Game::input() {
    SDL_Event e;
    int i = 3;
    while (69) {
        if (!i) return;
        if (SDL_PollEvent(&e) == 0) {
            i--;
            break;
        }
        if (e.type == SDL_QUIT) this->queueEvent(0, Layer::EVENT_QUIT, 0);
        else if (e.type == SDL_KEYDOWN) this->queueEvent(0, Layer::EVENT_KEY, e.key.keysym.sym);
    }
}

void Game::runEvents() {
    for (int i = 0; i < this->queued; i++) {
        Layer *notifier = this->eventQueue[i].notifier;
        int type = this->eventQueue[i].type;
        int parameter = this->eventQueue[i].parameter;
        this->notify(notifier, type, parameter);
    }
    this->queued = 0;
}

void Game::queueEvent(Layer *notifier, int type, unsigned int parameter) {
    this->eventQueue[this->queued].notifier = notifier;
    this->eventQueue[this->queued].type = type;
    this->eventQueue[this->queued].parameter = parameter;
    this->queued++;
}

Game::Game(int argc): graphics("bongo", Position(64, 48), argc > 1), content("content.db") {
    this->pushLayer(new Title());
}

void Game::run() {
    while (!this->kill) {
        //int time = SDL_GetTicks();
        this->display(&graphics);
        graphics.frame();
        this->input();
        this->runEvents();
        //std::cout << SDL_GetTicks() - time << std::endl;
    }
}

int Game::event(int type, unsigned int parameter) {
    if (type == Layer::EVENT_QUIT) {
        this->kill = true;
        return true;
    } else if (type == Layer::EVENT_MAP) {
        this->popLayer();
        this->pushLayer(new Level(Generator::generate(&content, 0, 0), Position(50, 50)));
        return true;
    }
    return false;
}

void Game::render(Graphics *graphics) {
    // does nothing.
}
