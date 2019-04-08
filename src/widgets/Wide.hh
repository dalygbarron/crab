#ifndef WIDE_H
#define WIDE_H

#include "../Widget.hh"

/**
 * Fits so that the children can all go on top of one another.
 */
class Wide: public Widget {
    void fit() {
        this->width = 0;
        this->height = 0;
        for (Widget *content: this->contents) {
            int childWidth = content->getWidth();
            int childHeight = content->getHeight();
            this->width += childWidth;
            if (childHeight > this->height) this->height = childHeight;
        }

    }
};

#endif
