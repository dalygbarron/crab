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
    const unsigned char fg;
    const unsigned char bg;
    const char *name;
    const int index;
};

#endif
