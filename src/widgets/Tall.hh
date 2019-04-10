#ifndef TALL_H
#define TALL_H

#include "../Widget.hh"

/**
 * Fits so that the contents can all go on top of one another.
 */
class Tall: public Widget {
    void fit() {
        this->width = 0;
        this->height = 0;
        for (Widget *content: this->contents) {
            int contentWidth = content->getWidth();
            int contentHeight = content->getHeight();
            if (contentWidth > this->width) this->width = contentWidth;
            this->height += contentHeight;
        }

    }
};

#endif
