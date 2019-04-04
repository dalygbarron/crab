#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Graphics.hh"
#include "Floor.hh"
#include "Wall.hh"

/**
 * This has all floors and walls and shit like that.
 * Also contains items and other things.
 */
class Map {
    int width;
    int height;
    unsigned char *tiles;

public:
    static const int LAYER_FLOOR = 0;
    static const int LAYER_WALL = 1;
    static const int LAYER_SINK = 2;
    static const int LAYER_CARDINAL = 3;
    static const int LAYER_N = 4;

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
    Map(std::istream *stream);

    /**
     * Deletes the junk.
     */
    ~Map();

    /**
     * Gets a tile code from the layers of the map and hands it to you.
     * @param x is the left of the tile.
     * @param y is the top of the tile.
     * @param z is which layer to get the tile from.
     * @return the code that corresponds to something depending on the layer it is from.
     */
    unsigned char getTile(int x, int y, int z);

    /**
     * Sets a tile to a value.
     * @param x is the left of the tile.
     * @param y is the top of the tile.
     * @param z is which layer to get the tile from.
     */
    void setTile(unsigned char value, int x, int y, int z);

    /**
     * Renders the map to the screen in a bounded area.
     * @param graphics is the renderer.
     * @param x        is the left side of the box the map is rendered in.
     * @param y        is the top side of the box the map is renderered in.
     * @param w        is the width of the box the map is rendered in.
     * @param h        is the height of the box the map is rendered in.
     * @param mx       is the left of the tile that should appear in the middle of the map view.
     * @param my       is the top of the tile that should appear in the middle of the map view.
     */
    void render(Graphics *graphics, int x, int y, int w, int h, int mx, int my);

    /**
     * Recalculates all the generic pathfinding paths the map stores. These maps can be used to find
     * the direction to walk in towards the player from any location on the map by moving from a
     * tile with a higher value to a lower one.
     * @param x is the horizontal pathfinding target
     * @param y is the vertical pathfinding target.
     */
    void microwave(int x, int y);

    /**
     * Writes the map out to a stream.
     * @param stream is the output it writes to.
     */
    void output(std::ostream *stream);
};

#endif
