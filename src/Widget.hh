#ifndef GUI_H
#define GUI_H

#include "Layer.hh"
#include <list>
#include "Graphics.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget: public Layer {
protected:
    Position dimensions;
    std::list<Widget *> contents;
    Widget *container = 0;

    /**
     * Adds an event to the queue via this widget's container, unless this is the container in which case it calls the
     * normal queue event method with itself as the sneder.
     * @param type      is the type of event.
     * @param parameter is a parameter to go with the event.
     */
    void containerEvent(int type, unsigned int parameter);

public:
    /**
     * Destroys the widget and all it's children recursively.
     */
    virtual ~Widget();

    /**
     * Adds another widget to this widget's contents.
     * @param content is the thing to add.
     */
    void addContent(Widget *content);

    /**
     * Gives the width of this widget. This doesn't necessarily have to to be followed but might be
     * handy for certain parent widgets.
     * @return the width.
     */
    Position getDimensions();

    /**
     * Resets the widget's width and height to what it deems appropriate.
     */
    virtual void fit() = 0;

    /**
     * Displays the GUI thingy for your enjoyment anywhere on the screen.
     * @param graphics is the rendering system.
     * @param pos      is the location at which to do the rendering.
     */
    virtual void render(Graphics *graphics, Position pos) = 0;

    virtual void render(Graphics *graphics) override;

    virtual int event(int type, unsigned int parameter) override;
};


#endif
