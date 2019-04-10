#ifndef MAP_H
#define MAP_H

#include <forward_list>
#include <iostream>
#include "Graphics.hh"
#include "Floor.hh"
#include "Wall.hh"
#include "Vector.hh"
#include "Move.hh"

/**
 * Forward declaration.
 */
class Creature;

/**
 * This has all floors and walls and shit like that.
 * Also contains items and other things.
 */
class Map {
    Position dimensions;
    unsigned char *tiles;
    std::forward_list<Creature *> creatures;

public:
    static const unsigned char LAYER_FLOOR = 0;
    static const unsigned char LAYER_WALL = 1;
    static const unsigned char LAYER_SINK = 2;
    static const unsigned char LAYER_CARDINAL = 3;
    static const unsigned char LAYER_N = 4;

    Colour topColour = Colour::NAVY;
    Colour bottomColour = Colour::BLACK;


    /**
     * Creates the map as a square of given width and height.
     * @param dimensions is the width and height of the map.
     */
    Map(Position dimensions);

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
     * Gets the floor tile object at a given location.
     * @param position is the location to get the floor for.
     * @return a pointer to the actual floor object.
     */
    const Floor *getFloor(Position position) const;

    /**
     * Gets a tile code from the layers of the map and hands it to you.
     * @param is the top down position to get the tile for.
     * @param z is which layer to get the tile from.
     * @return the code that corresponds to something depending on the layer it is from.
     */
    unsigned char getTile(Position position, int z) const;

    /**
     * Sets a tile to a value.
     * @param value is the new value to set it to.
     * @param position is the top down location of the tile.
     * @param z is which layer to get the tile from.
     */
    void setTile(unsigned char value, Position position, int z);

    /**
     * Puts a creature into the map at the given location.
     * @param creature is the creature to add.
     * @param position is it's new location in the map.
     */
    void addCreature(Creature *creature, Position position);

    /**
     * Applies a move to the map and alters it's state by it's effects.
     * @param move is the move to apply.
     */
    void applyMove(Move move);

    /**
     * Renders the map to the screen in a bounded area.
     * @param graphics is the renderer.
     * @param rect     is the area the rendering must take place in.
     * @param middle   is what position should appear in the middle of the screen.
     */
    void render(Graphics *graphics, Rect rect, Position middle);

    /**
     * Recalculates all the generic pathfinding paths the map stores. These maps can be used to find
     * the direction to walk in towards the player from any location on the map by moving from a
     * tile with a higher value to a lower one.
     * @param position is the position that should be the target for path finding.
     */
    void microwave(Position position);

    /**
     * Writes the map out to a stream.
     * @param stream is the output it writes to.
     * TODO: could replace this with stream operator which would be cool.
     */
    void output(std::ostream *stream);
};

#endif
