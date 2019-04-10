#ifndef LAYER_H
#define LAYER_H

#include "Graphics.hh"

/**
 * Represents a unit of user interface stuff that reacts to user input events and renders as a whole, for example, a
 * screen of the game, or a pop up menu.
 * These are structured as a stack heirachy where the topmost layer on the stack is rendered on top and has first pick
 * of events to process.
 */
class Layer {
    Layer *parent = 0;
    Layer *child = 0;

    /**
     * How this layer reacts to an event.
     * @param type      is the type of event it is.
     * @param parameter is a parameter to the event.
     * @return true if the event was consumed, and false if not.
     */
    virtual int event(int type, unsigned int parameter) = 0;

    /**
     * Layer's unique rendering functionality.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;

    /**
     * Tries to process an event and if it is not useful it sends it to the parent layer recursively.
     * @param notifier  is the one sending the event so it can skip processing it. If you might want to process your
     *                  own event then just pass 0 to this.
     * @param type      is the type of event it is.
     * @param parameter is a parameter to the event.
     */
    void report(Layer *notifier, int type, unsigned int parameter);

protected:
    /**
     * Sends an event to the top of the layer stack so it can be passed back down from the top.
     * @param notifier  is the one sending the event so it can skip processing it.
     * @param type      is the type of event it is.
     * @param parameter is a parameter to the event.
     */
    void notify(Layer *notifier, int type, unsigned int parameter);

    /**
     * Sends a message down the stack to be queued at the queueing layer.
     * This method is virtual so that the layer which maintains the queue can add the message to the queue when this
     * method is called.
     * @param notifier  is the one who sent the event.
     * @param type      is the kind of event it is.
     * @param parameter is an extra parameter to the event like a key code to a key press event etc.
     */
    virtual void queueEvent(Layer *notifier, int type, unsigned int parameter);

public:
    const int EVENT_QUIT = 0;
    const int EVENT_KEY = 1;
    const int EVENT_WIDGET_CLOSE = 2;
    const int EVENT_WIDGET_UPDATE = 3;
    const int EVENT_MAP = 4;

    /**
     * Hell yeah destructo time.
     */
    virtual ~Layer();

    /**
     * Places a layer at the top of the stack of layers. If this layer alreaady has a child then it will have this
     * method called on it recursively until it reaches the top of the stack.
     * @param layer is the layer we are adding.
     */
    void pushLayer(Layer *layer);

    /**
     * Removes the layer directly on top of this one and deletes it (recurs on children).
     */
    void popLayer();

    /**
     * Renders the layer and all layers on top of it.
     * @param graphics is the graphics system to render with.
     */
    void display(Graphics *graphics);
};

#endif
