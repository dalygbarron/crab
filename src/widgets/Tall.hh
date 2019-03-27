#ifndef TALL_H
#define TALL_H

#include "../Widget.hh"

/**
 * Fits so that the children can all go on top of one another.
 */
class Tall: public Widget {
    void fit() {
        this->width = 0;
        this->height = 0;
        for (Widget *child: this->children) {
            int childWidth = child->getWidth();
            int childHeight = child->getHeight();
            if (childWidth > this->width) this->width = childWidth;
            this->height += childHeight;
        }

    }
};

#endif
