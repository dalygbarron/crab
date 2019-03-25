#ifndef LIST_H
#define LIST_H

#include "../Widget.hh"
#include <forward_list>
#include <iostream>
#include <SDL2/SDL.h>

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class ListSelector: public Widget {
    int index = 0;
    int offset = 0;

public:
    int logic(Graphics *graphics) {
        int key = graphics->input();
        if (key == SDLK_UP) {
            this->index--;
            if (this->index < 0) this->index = this->n - 1;
        } else if (key == SDLK_DOWN) {
            this->index++;
            if (this->index >= this->n) this->index = 0;
        } else if (key == SDLK_RETURN) {
            return this->index;
        }
        return -1;
    }

    void render(Graphics *graphics, int x, int y, int w, int h) {
        graphics->blitBox(x, y + this->index, w, 1, Graphics::ORANGE);
        int i = 0;
        for (Widget *child: this->children) {
            child->render(graphics, x, y + i, w, h);
            i++;
        }
    }
};

#endif
