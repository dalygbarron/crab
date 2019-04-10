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
    const unsigned char tile;
    const Colour colour;
    const char *description;
    const char blockSight;
    const char blockMove;

    /**
     * Generic constructor.
     */
    Wall();

    /**
     * Creates the wall and gives it all it's stuff.
     * @param tile        is the tile that the wall renders as.
     * @param colour      is the colour of the wall tile.
     * @param description is the textual description of the wall.
     */
    Wall(unsigned char tile, Colour colour, const char *description);

};

#endif
