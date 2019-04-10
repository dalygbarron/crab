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
    const unsigned char tile;
    const Colour colour;
    const char *description;

    /**
     * Generic constructor.
     */
    Floor();

    /**
     * Builds a floor with it's things.
     * @param tile        is the tile it should render as.
     * @param colour      is the colour it is drawn in.
     * @param description is the text description of the tile.
     */
    Floor(unsigned char tile, Colour colour, const char *description);

};

#endif
