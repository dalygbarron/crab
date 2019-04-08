#include "Layer.hh"

void Layer::pushLayer(Layer *layer) {
    if (this->layer) this->layer->pushLayer(layer);
    else {
        this->layer = layer;
        Speaker::pushListener(layer;)
    }
}

void Layer::popLayer() {
    if (this->layer) {
        delete this->layer;
        this->layer = NULL;
    }
}
