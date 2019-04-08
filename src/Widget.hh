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
class Widget: public Layer {
protected:
    int width = 1;
    int height = 1;
    std::list<Widget *> contents;

public:
    /**
     * Destroys the widget and all it's children recursively.
     */
    virtual ~Widget();

    virtual int event(void *speaker, int type, unsigned int parameter) override;

    /**
     * Adds a widget inside this widget so it will render it and stuff like that.
     * @param content is the widget to add to the widget in order.
     */
    void addContent(Widget *content);

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

    virtual void render(Graphics *graphics) override;

    /**
     * Render in position.
     * @param graphics is the renderer.
     * @param x        is the left position to start drawing.
     * @param y        is the top position to start drawing.
     */
    virtual void render(Graphics *graphics, int x, int y) = 0;
};


#endif
