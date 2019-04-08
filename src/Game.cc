#include "Game.hh"
#include <iostream>
#include "Input.hh"
#include "scenes/Title.hh"
#include "Observer.hh"


Game::Game(int argc): graphics("bongo", 64, 48, argc > 1) {
    Speaker::pushListener(this);
    this->setScene(new Title(&this->input));
}

int Game::event(void *speaker, int type, unsigned int parameter) {
    if (type == Speaker::EVENT_QUIT) {
        this->kill = true;
        return true;
    } else if (type == Speaker::EVENT_MAP) {
        delete this->scene;
        this->setScene(new Level(&this->input, generator.generate(0, 0)));
    }
    return false;
}

void Game::setScene(Scene *scene) {
    this->scene = scene;
    Speaker::pushListener(scene);
}

void Game::run() {
    while (!this->kill) {
        this->scene->display(&this->graphics);
        graphics.frame();
        this->input.update();
    }
}
