#ifndef WIDE_H
#define WIDE_H

#include "../Widget.hh"
#include <iostream>

/**
 * Fits so that the contents can all go on top of one another.
 */
class Wide: public Widget {
    void fit() override {
        this->dimensions = Position();
        for (Widget *content: this->contents) {
            Position contentDimensions = content->getDimensions();
            this->dimensions.x += contentDimensions.x;
            if (contentDimensions.y > this->dimensions.y) this->dimensions.y = contentDimensions.y;
        }
    }
};

#endif
