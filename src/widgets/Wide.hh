#ifndef WIDE_H
#define WIDE_H

#include "../Widget.hh"

/**
 * Fits so that the contents can all go on top of one another.
 */
class Wide: public Widget {
    void fit() {
        this->width = 0;
        this->height = 0;
        for (Widget *content: this->contents) {
            int contentWidth = content->getWidth();
            int contentHeight = content->getHeight();
            this->width += contentWidth;
            if (contentHeight > this->height) this->height = contentHeight;
        }

    }
};

#endif
