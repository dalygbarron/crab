#ifndef HBOX_H
#define HBOX_H

#include "../Widget.hh"
#include <SDL2/SDL.h>
#include "../Graphics.hh"

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class HBox: public Widget {
    int index = 0;

public:
    int logic(Graphics *graphics, int key) {
        if (key == SDLK_LEFT) {
            index--;
        } else if (key == SDLK_RIGHT) {
            index++;
        } else {
            int i = 0;
            for (Widget *child: this->children) {
                if (i == index) return child->logic(graphics, key);
                i++;
            }
        }
        return -1;
    }

    void render(Graphics *graphics, int x, int y) {
        int offset = 0;
        int i = 0;
        for (Widget *child: this->children) {
            if (i == offset) graphics->blitBox(x + offset, y, this->width, this->height, Graphics::ORANGE);
            child->render(graphics, x + offset, y);
            i++;
        }
    }
};

#endif
