#include "Game.hh"
#include "Input.hh"
#include "scenes/Title.hh"


Game::Game(int argc): Graphics("bongo", 64, 48, argc > 1) {
    this->input->pushListener(this);
    this->scene = new Title();
}

int Game::event(int type, int parameter) {
    if (type != Input::EVENT_QUIT) return false;
    // TODO: do proper quitting.
}

void Game::run() {
    while (!this->kill) {
        this->scene->render();
        this->input->update();
    }
}
