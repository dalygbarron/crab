#ifndef INPUT_H
#define INPUT_H

#include "Observer.hh"

/**
 * Takes care of input and that kind of shit. This should not be created before the graphics object is since that
 * initializes sdl.
 */
class Input: public Speaker {
public:
    /**
     * Updates the input system and checks if there is anything interesting to look for.
     */
    void update();
};

#endif
