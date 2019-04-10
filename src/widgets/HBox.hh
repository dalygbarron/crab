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
    int event(int type, unsigned int parameter) override {
        if (type == Layer::EVENT_KEY) {
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
                    if (i == index) return content->event(type, parameter);
                    i++;
                }
            }
        }
        return false;
    }

    void render(Graphics *graphics, Position pos) override {
        int offset = 0;
        int i = 0;
        Rect box(pos, this->dimensions);
        graphics->blitBox(box, Colour::BLACK);
        for (Widget *content: this->contents) {
            box.size = content->getDimensions();
            if (i == this->index) graphics->blitBox(box, Colour::NAVY);
            content->render(graphics, box.pos);
            box.pos.x += box.size.x;
            i++;
        }
    }
};

#endif
