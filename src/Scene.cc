#include "Scene.hh"

Scene *Scene::execute(Graphics *graphics) {
    graphics->frame();
    this->render(graphics);
    Scene *next = this->logic(graphics);
    return next;
}
