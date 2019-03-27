#ifndef HBOX_H
#define HBOX_H

#include "Wide.hh"
#include <SDL2/SDL.h>
#include "../Graphics.hh"

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class HBox: public Wide {
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
        graphics->blitBox(x, y, this->getWidth(), this->getHeight(), Graphics::BLACK);
        for (Widget *child: this->children) {
            if (i == this->index) {
                graphics->blitBox(
                    x + offset,
                    y,
                    child->getWidth(),
                    child->getHeight(),
                    Graphics::NAVY
                );
            }
            child->render(graphics, x + offset, y);
            offset += child->getWidth();
            i++;
        }
    }
};

#endif
