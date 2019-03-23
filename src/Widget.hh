#ifndef GUI_H
#define GUI_H

#include <deque>
#include "Graphics.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget {
protected:
    int w;
    int h;

public:
    /**
     * Gives the gui element it's basic shape within which it must fit.
     * @param x is it's left offset.
     * @param y is the it's top offset.
     * @param w is it's width.
     * @param h is it's height.
     */
    Widget(int w, int h);

    /**
     * Gives the gui item a chance to update itself and receive user input.
     * @param key is the user input that it gets.
     * @return a number >= 0 to tell us that some shit is going down.
     */
    virtual int update(int key);

    /**
     * Displays the GUI thingy for your enjoyment.
     * @param graphics is the rendering system.
     * @param x is the left location to start rendering.
     * @param y is the top location to start rendering.
     */
    virtual void render(Graphics *graphics, int x, int y) = 0;
};


#endif
