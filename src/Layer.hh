#ifndef LAYER_H
#define LAYER_H

#include "Observer.hh"
#include "Graphics.hh"

class Layer: public Listener {
protected:
    Layer *parent = NULL;
    Layer *child = NULL;

public:
    /**
     * Deletes the layer and all child layers.
     */
    virtual ~Layer();

    /**
     * Places a layer at the top of the stack of layers. If this layer alreaady has a child then it will have this
     * method called on it recursively until it reaches the top of the stack.
     * @param layer is the layer we are adding.
     */
    void pushLayer(Layer *layer);

    /**
     * Renders the layer and all layers on top of it.
     * @param graphics is the graphics system to render with.
     */
    void display(Graphics *graphics);

    /**
     * Layer's unique rendering functionality.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;
};

#endif
