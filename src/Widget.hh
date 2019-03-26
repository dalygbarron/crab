#ifndef GUI_H
#define GUI_H

#include <forward_list>
#include "Graphics.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget {
    int nChildren = 0;
protected:
    int width;
    int height;
    std::forward_list<Widget *> children;

public:
    /**
     * Destroys the widget and all it's children recursively.
     */
    virtual ~Widget();

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
     * Run the widget and return once it's completely done.
     * @param graphics is used for input and display.
     * @return int which is >= 0 when something cool is happening.
     */
    int execute(Graphics *graphics, int x, int y, int w, int h);

    /**
     * Gives the gui item a chance to update itself and receive user input.
     * @param graphics is used to execute more widgets.
     * @param key      is the user input key. This should be sent in so an owner widget can selectively run children.
     * @return a number >= 0 to tell us that some shit is going down.
     */
    virtual int logic(Graphics *graphics, int key);

    /**
     * Displays the GUI thingy for your enjoyment.
     * @param graphics is the rendering system.
     * @param x        is the left location to start rendering.
     * @param y        is the top location to start rendering.
     * @param w        is the bounding width.
     * @param h        is the bounding height;
     */
    virtual void render(Graphics *graphics, int x, int y, int w, int h) = 0;
};


#endif
