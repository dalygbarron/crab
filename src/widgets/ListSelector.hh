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
    std::forward_list<Widget *> *list;

public:
    ListSelector(
        int w,
        int h,
        std::forward_list<Widget *> *list
    ): Widget(w, h) {
        this->list = list;
    }

    ~ListSelector() {
        for (Widget *widget: *list) delete widget;
    }

    int update(int key) {
        if (key == SDLK_UP) {
            this->index--;
        } else if (key == SDLK_DOWN) {
            this->index++;
        } else if (key == SDLK_RETURN) {
            return this->index;
        }
        return -1;
    }

    void render(Graphics *graphics, int x, int y) {
        graphics->blitBox(x, y + this->index, this->w, 1, Graphics::ORANGE);
        int i = 0;
        for (Widget *widget: *list) {
            widget->render(graphics, x, y + i);
            i++;
        }
    }
};

#endif
