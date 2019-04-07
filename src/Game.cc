#include "Game.hh"
#include "Input.hh"
#include "scenes/Title.hh"


Game::Game(int argc): graphics("bongo", 64, 48, argc > 1) {
    this->input.pushListener(this);
    this->scene = new Title(&this->input);
    input.pushListener(this->scene);
}

int Game::event(Speaker *speaker, int type, int parameter) {
    if (type != Listener::EVENT_QUIT) return false;
    this->kill = true;
    return true;
}

void Game::run() {
    while (!this->kill) {
        this->scene->display(&this->graphics);
        graphics.frame();
        this->input.update();
    }
}
