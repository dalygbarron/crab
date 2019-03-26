#include "Scene.hh"
#include <iostream>

Scene::~Scene() {
    // does nothing.
}

Scene *Scene::execute(Graphics *graphics) {
    this->render(graphics);
    graphics->frame();
    Scene *next = this->logic(graphics);
    std::cout << "q" << std::endl;
    return next;
}
