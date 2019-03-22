#include "Title.hh"
#include "../Scene.hh"
#include <iostream>
#include <string>
#include <cstdlib>

Title::Title(std::string *word) {
    this->word = word;
}

void Title::update(int key, struct Transition *transition) {
    transition->scene = this;
    this->x += 1;
    this->y += 1;
}

void Title::render(Graphics *graphics) {
    graphics->flush(rand() % 0xffffff);
    graphics->blitTile(x, x, y, 0xff00ff, 0xff0000);
    graphics->frame();
}
