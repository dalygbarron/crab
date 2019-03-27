#ifndef MAP_H
#define MAP_H

#include <iostream>

/**
 * This has all floors and walls and shit like that.
 * Also contains items and other things.
 */
class Map {
    unsigned char *warmths;
    Wall const **walls;
    int width;
    int height;

public:
    static const int WARMTH_SINK = 0;
    static const int WARMTH_CARDINAL = 1;
    static const int WARMTH_N = 2;

    /**
     * Creates the map as a square of given width and height.
     * @param width  is the width of the map.
     * @param height is the height of the map.
     */
    Map(int width, int height);

    /**
     * Loads the map from an input stream.
     * @param stream is the input stream to read the map from.
     */
    Map(istream *stream);

    /**
     * Deletes the junk.
     */
    virtual ~Map();

    /**
     * Tells you what wall is at a given location.
     * @param x is the horizontal position.
     * @param y is the vertical position.
     * @return a pointer to the prototypal wall.
     */
    Wall const *getWall(int x, int y);

    /**
     * Sets the wall at the given point to a given wall.
     * @param x    is the horizontal location.
     * @param y    is the vertical location.
     * @param wall is the wall to set it to. NULL for no wall.
     */
    void setWall(int x, int y, Wall const *wall);

    /**
     * Gets the value of a generated pathfinding map at a given location. These pathfinding maps are used for enemies
     * to find their way to the player and can be used from any location. However, for special pathfinding to some
     * other target a path must be specially generated another way.
     * @param x    is the horizontal location.
     * @param y    is the vertical location.
     * @param type is which pathfinding map to use.
     */
    unsigned char getWarmth(int x, int y, int type);

    /**
     * Recalculates all the pathfinding paths the map stores.
     * @param x is the horizontal target.
     * @param y is the vertical target.
     */
    void recalculateWarmth(int x, int y);

    /**
     * Writes the map out to a stream.
     * @param stream is the output it writes to.
     */
    void output(ostream *stream);
};

#endif
