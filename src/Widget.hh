#ifndef GUI_H
#define GUI_H

#include "Graphics.hh"

/**
 * Represents some aspect of the gui like a button or a selecty thingy or some text I guess.
 */
class Widget {
public:
    /**
     * Run the widget and return once it's completely done.
     * @param graphics is used for input and display.
     * @return int which is >= 0 when something cool is happening.
     */
    int execute(Graphics *graphics);

    /**
     * Gives the gui item a chance to update itself and receive user input.
     * @param key is the user input that it gets.
     * @return a number >= 0 to tell us that some shit is going down.
     */
    virtual int logic(int key);

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
