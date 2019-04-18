#ifndef WALL_H
#define WALL_H

#include "Graphics.hh"

/**
 * Represents a prototypal blockage that can appear on the map that cannot be walked over but may be able to be
 * destroyed and may or may not block line of sight etc.
 */
class Wall
{
public:
    unsigned char tile;
    Colour colour;
    const char *description;
    int blockSight;
    int blockMove;

    /**
     * Generic constructor.
     */
    Wall();

};

#endif
