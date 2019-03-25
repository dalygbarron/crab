#include "Scene.hh"

Scene *Scene::execute(Graphics *graphics) {
    Scene *next = this->logic(graphics->input());
    this->render(graphics);
    graphics->frame();
    return next;
}
