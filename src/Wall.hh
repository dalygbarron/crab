#ifndef WALL_H
#define WALL_H

/**
 * Represents a prototypal blockage that can appear on the map that cannot be walked over but may be able to be
 * destroyed and may or may not block line of sight etc.
 */
class Wall
{
public:
    unsigned char tile;
    unsigned char fg;
    unsigned char bg;
    char const *name;
    char blockSight;
    char blockMove;

};

#endif
