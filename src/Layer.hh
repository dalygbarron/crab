#ifndef LAYER_H
#define LAYER_H

class Layer {
    Layer *parent = NULL;
    Layer *child = NULL;

    /**
     * Layer's unique rendering functionality.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;

public:
    /**
     * Places a layer at the top of the stack of layers. If this layer alreaady has a child then it will have this
     * method called on it recursively until it reaches the top of the stack.
     * @param layer is the layer we are adding.
     */
    void pushLayer(Layer *layer);

    /**
     * Removes the layer directly on top of this one and deletes it.
     */
    void popLayer();

    /**
     * Renders the layer and all layers on top of it.
     * @param graphics is the graphics system to render with.
     */
    void display(Graphics *graphics);
};

#endif
