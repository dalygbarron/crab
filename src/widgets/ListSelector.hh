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
    Widget *list;
    int n = 0;

public:
    ListSelector(Widget *list, int n){
        this->list = list;
        this->n = n;
    }

    int logic(int key) {
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
        graphics->blitBox(x, y, w, h, Graphics::NAVY);
        graphics->blitBox(x, y + this->index, w, 1, Graphics::ORANGE);
        for (int i = 0; i < h; i++) {
            widget->render(graphics, x, y + i);
        }
    }
};

#endif
