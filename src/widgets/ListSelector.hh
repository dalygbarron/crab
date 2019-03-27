#ifndef LIST_H
#define LIST_H

#include "../Widget.hh"
#include <SDL2/SDL.h>

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class ListSelector: public Widget {
    int index = 0;
    int offset = 0;

public:
    int logic(Graphics *graphics, int key) {
        if (key == SDLK_UP) {
            this->index--;
            if (this->index < 0) this->index = this->children.size() - 1;
        } else if (key == SDLK_DOWN) {
            this->index++;
            if (this->index >= this->children.size()) this->index = 0;
        } else if (key == SDLK_RETURN) {
            return this->index;
        }
        return -1;
    }

    void render(Graphics *graphics, int x, int y) {
        int i = 0;
        int offset = 0;
        for (Widget *child: this->children) {
            int height = child->getHeight();
            if (i == this->index) graphics->blitBox(x, y + offset, child->getWidth(), height, Graphics::ORANGE);
            child->render(graphics, x, y + offset);
            offset += height;
            i++;
        }
    }
};

#endif
