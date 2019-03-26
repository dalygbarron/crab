#ifndef FRAME_H
#define FRAME_H

#include "../Widget.hh"
#include <iostream>
#include "../Graphics.hh"

class Frame: public Widget {
    int colour;
public:
    Frame(int colour) {
        this->colour = colour;
    }

    void render(Graphics *graphics, int x, int y, int w, int h) {
        graphics->blitBox(x, y, w, h, colour);
        int offset = 0;
        for (Widget *child: this->children) {
            child->render(graphics, x, y + offset, w, h);
            offset += child->getHeight();
        }
    }
};

#endif
