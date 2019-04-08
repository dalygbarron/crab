#include "Game.hh"
#include <iostream>
#include "Input.hh"
#include "scenes/Title.hh"


Game::Game(int argc): graphics("bongo", 64, 48, argc > 1) {
    this->input.pushListener(this);
    this->setScene(new Title(&this->input));
}

int Game::event(Speaker *speaker, int type, int parameter) {
    if (type == Speaker::EVENT_QUIT) {
        this->kill = true;
        return true;
    } else if (type == Speaker::EVENT_MAP) {
        this->setScene(new Level(&this->input, generator.generate(0, 0)));
    }
    return false;
}

void Game::setScene(Scene *scene) {
    if (this->scene) {
        this->scene->removeGui(&this->input);
        delete this->scene;
    }
    this->scene = scene;
    scene->pushListener(this);
}

void Game::run() {
    while (!this->kill) {
        this->scene->display(&this->graphics);
        graphics.frame();
        this->input.update();
    }
}
