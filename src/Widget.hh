#ifndef GUI_H
#define GUI_H

#include "Observer.hh"
#include <list>
#include "Graphics.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget: public Listener {
    int nChildren = 0;
protected:
    int width = 1;
    int height = 1;
    std::list<Widget *> children;

public:
    /**
     * Destroys the widget and all it's children recursively.
     */
    virtual ~Widget();

    /**
     * Override.
     */
    virtual int event(int type, int parameter);

    /**
     * Adds a child to this widget so it will render it and stuff.
     * @param child is the child to add to the widget in order.
     */
    void addChild(Widget *child);

    /**
     * Gets the number of children that this widget has.
     * @return int number of children.
     */
    int getNChildren();

    /**
     * Gives the width of this widget. This doesn't necessarily have to to be followed but might be
     * handy for certain parent widgets.
     * @return the width.
     */
    int getWidth();

    /**
     * Gives the height of this widget. This doesn't necessarily have to to be followed but might be
     * handy for certain parent widgets.
     * @return the height.
     */
    int getHeight();

    /**
     * Resets the widget's width and height to what it deems appropriate.
     */
    virtual void fit() = 0;

    /**
     * Displays the GUI thingy for your enjoyment.
     * @param graphics is the rendering system.
     * @param x        is the left location to start rendering.
     * @param y        is the top location to start rendering.
     * @param w        is the bounding width.
     * @param h        is the bounding height;
     */
    virtual void render(Graphics *graphics, int x, int y) = 0;
};


#endif
