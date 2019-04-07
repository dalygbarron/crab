#include "Scene.hh"
#include <iostream>
#include "Graphics.hh"

Scene::~Scene() {
    this->removeGui();
}

void Scene::addGui(Input *input, Widget *gui) {
    if (this->gui) delete this->gui;
    this->gui = gui;
    input->pushListener(gui);
    gui->pushListener(this);
}

void Scene::removeGui() {
    if (this->gui) {
        delete this->gui;
        this->gui = NULL;
    }
}

void Scene::display(Graphics *graphics) {
    this->render(graphics);
    if (this->gui) this->gui->render(graphics, 0, 0);
}
