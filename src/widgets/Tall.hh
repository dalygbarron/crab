#ifndef TALL_H
#define TALL_H

#include "../Widget.hh"

/**
 * Fits so that the contents can all go on top of one another.
 */
class Tall: public Widget {
    void fit() override {
        this->dimensions = Position();
        for (Widget *content: this->contents) {
            Position contentDimensions = content->getDimensions();
            this->dimensions.y += contentDimensions.y;
            if (contentDimensions.x > this->dimensions.x) this->dimensions.x = contentDimensions.x;
        }
    }
};

#endif
