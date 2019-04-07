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
    int event(Speaker *speaker, int type, int parameter) {
        if (type == Listener::EVENT_KEY) {
            if (parameter == SDLK_LEFT) {
                this->index--;
                return true;
            } else if (parameter == SDLK_RIGHT) {
                this->index++;
                return true;
            } else {
                // TODO: this is pure autism.
                int i = 0;
                for (Widget *child: this->children) {
                    if (i == index) return child->event(speaker, type, parameter);
                    i++;
                }
            }
        }
        return false;
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
