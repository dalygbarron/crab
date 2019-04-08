#include "Layer.hh"
#include <iostream>
#include "Observer.hh"

Layer::~Layer() {
    if (this->child) delete this->child;
}

void Layer::pushLayer(Layer *layer) {
    if (this->child) this->child->pushLayer(layer);
    else {
        this->child = layer;
        Speaker::pushListener(layer);
    }
}

void Layer::display(Graphics *graphics) {
    Layer *layer = this;
    layer->render(graphics);
    while(layer->child) {
        layer = layer->child;
        layer->render(graphics);
    }
}
