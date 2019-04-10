#include "Layer.hh"
#include <iostream>

void Layer::notify(Layer *notifier, int type, unsigned int parameter) {
    if (this->child) this->child->notify(notifier, type, parameter);
    else this->report(notifier, type, parameter);
}

void Layer::report(Layer *notifier, int type, unsigned int parameter) {
    if (this != notifier && this->event(type, parameter)) return;
    else if (this->parent) this->parent->report(notifier, type, parameter);
    else std::cerr << "event not reported:(" << type << ',' << parameter << ')' << std::endl;
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
