#include "Layer.hh"
#include <iostream>

void Layer::notify(Layer *notifier, int type, unsigned int parameter) {
    // get to top of the stack.
    Layer *current = this;
    while (current->child) current = current->child;
    // come back down the stack.
    while (true) {
        if (current != notifier && current->event(type, parameter)) {
            return;
        } else if (current->parent) {
            current = current->parent;
        } else {
            std::cerr << "event not reported:(" << type << ',' << parameter << ')' << std::endl;
            return;
        }
    }
}

void Layer::queueEvent(Layer *notifier, int type, unsigned int parameter) {
    if (this->parent) this->parent->queueEvent(notifier, type, parameter);
    else std::cerr << "Event lost:(" << type << ',' << parameter << ')' << std::endl;
}

void Layer::display(Graphics *graphics) {
    this->render(graphics);
    if (this->child) this->child->display(graphics);
}

Layer::~Layer() {
    if (this->child) delete this->child;
}

void Layer::pushLayer(Layer *layer) {
    if (this->child) this->child->pushLayer(layer);
    else {
        this->child = layer;
        layer->parent = this;
    }
}

void Layer::popLayer() {
    if (this->child) {
        delete this->child;
        this->child = 0;
    }
}
