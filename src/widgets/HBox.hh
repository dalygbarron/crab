#ifndef HBOX_H
#define HBOX_H

#include "Wide.hh"
#include <SDL2/SDL.h>
#include <iostream>
#include "../Graphics.hh"

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class HBox: public Wide {
    int index = 0;

public:
    int event(void *speaker, int type, unsigned int parameter) override {
        if (type == Speaker::EVENT_KEY) {
            if (parameter == SDLK_LEFT) {
                this->index--;
                return true;
            } else if (parameter == SDLK_RIGHT) {
                this->index++;
                return true;
            } else {
                // TODO: this is pure autism.
                int i = 0;
                for (Widget *content: this->contents) {
                    if (i == index) return content->event(speaker, type, parameter);
                    i++;
                }
            }
        }
        return false;
    }

    void render(Graphics *graphics, int x, int y) override {
        int offset = 0;
        int i = 0;
        graphics->blitBox(x, y, this->getWidth(), this->getHeight(), Graphics::BLACK);
        for (Widget *content: this->contents) {
            if (i == this->index) {
                graphics->blitBox(
                    x + offset,
                    y,
                    content->getWidth(),
                    content->getHeight(),
                    Graphics::NAVY
                );
            }
            content->render(graphics, x + offset, y);
            offset += content->getWidth();
            i++;
        }
    }
};

#endif
