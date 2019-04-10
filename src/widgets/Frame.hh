#ifndef FRAME_H
#define FRAME_H

#include "../Widget.hh"
#include <iostream>
#include "../Graphics.hh"

class Frame: public Widget {
    int colour;
public:
    Frame(int colour, int width, int heigh) {
        this->colour = colour;
        this->width = width;
        this->height = height;
    }

    void render(Graphics *graphics, int x, int y) {
        graphics->blitBox(x, y, this->width, this->height, colour);
        int offset = 0;
        for (Widget *content: this->contents) {
            content->render(graphics, x, y + offset);
            offset += content->getHeight();
        }
    }
};

#endif
