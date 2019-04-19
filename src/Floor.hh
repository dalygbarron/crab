#ifndef FLOOR_H
#define FLOOR_H

#include "Graphics.hh"

/**
 * Represents a prototypal floor that can be walked on. Will store and description and things like terrain type that
 * may affect movement speed for different types of thing.
 */
class Floor
{
public:
    unsigned char tile;
    Colour colour;
    const char *description;

    /**
     * Generic constructor.
     */
    Floor();

};

#endif
