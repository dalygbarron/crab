#ifndef LIST_H
#define LIST_H

#include "Tall.hh"
#include <SDL2/SDL.h>

/**
 * Displays a nice list stacked vertically of things that you may choose.
 */
class ListSelector: public Tall {
    int index = 0;
    int offset = 0;

public:
    int event(int type, unsigned int parameter) {
        if (type == Layer::EVENT_KEY) {
            if (parameter == SDLK_DOWN) {
                this->index++;
                return true;
            } else if (parameter == SDLK_UP) {
                this->index--;
                return true;
            } else if (parameter == SDLK_RETURN) {
                this->containerEvent(Layer::EVENT_WIDGET_CLOSE, this->index);
                return true;
            }
        }
        return false;
    }

    void render(Graphics *graphics, int x, int y) {
        int i = 0;
        int offset = 0;
        for (Widget *content: this->contents) {
            int height = content->getHeight();
            if (i == this->index) graphics->blitBox(x, y + offset, content->getWidth(), height, Graphics::ORANGE);
            content->render(graphics, x, y + offset);
            offset += height;
            i++;
        }
    }
};

#endif
