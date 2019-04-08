#ifndef GUI_H
#define GUI_H

#include "Observer.hh"
#include <list>
#include "Graphics.hh"
#include "Input.hh"
#include "Layer.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget: public Listener, public Layer {
    int nChildren = 0;

protected:
    int width = 1;
    int height = 1;
    Widget *parent = NULL;
    std::list<Widget *> children;
    Widget *gui = NULL;

    /**
     * Add a pop up widget that takes control away from this one.
     * @param gui   is the popup.
     */
    void addGui(Widget *gui);

    /**
     * Removes popup widget that is taking control from this one.
     */
    void removeGui();

public:
    /**
     * Destroys the widget and all it's children recursively.
     */
    virtual ~Widget();

    virtual int event(void *speaker, int type, int parameter) override;

    /**
     * If a widget is inside another widget then this sets that as this widget's parent.
     * @param parent is the parent widget.
     */
    void setParent(Widget *parent);

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
     * Gets this widget's parent to speak on it's behalf, unless there is no parent in which case it just speaks.
     * NB: This is what should pretty much always be used in widgets.
     * @param type      is the type of event.
     * @param parameter is a parameter to that event.
     */
    void parentSpeak(int type, int parameter);

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
