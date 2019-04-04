#ifndef FLOOR_H
#define FLOOR_H

/**
 * Represents a prototypal floor that can be walked on. Will store and description and things like terrain type that
 * may affect movement speed for different types of thing.
 */
class Floor
{
public:
    const unsigned char tile;
    const unsigned int fg;
    const unsigned int bg;
    const char *description;

    /**
     * Generic constructor.
     */
    Floor();

    /**
     * Builds a floor with it's things.
     * @param tile        is the tile it should render as.
     * @param fg          is the colour the tile is drawn in.
     * @param bg          is the colour behind the tile.
     * @param description is the text description of the tile.
     */
    Floor(unsigned char tile, unsigned int fg, unsigned int bg, const char *description);

};

#endif
