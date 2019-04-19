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
    int id = -1;
    Position dimensions;
    const Floor **floors;
    const Wall **walls;
    unsigned char *layers;
    Colour *light;
    Colour ambientLight = Colour(50, 0, 0);
    int layerSize;
    std::forward_list<Creature *> creatures;

    /**
     * Make a creature walk in a direction.
     * @param actor     is the creature walking.
     * @param direction is the direction to go in by the codes in Move.hh
     */
    void walk(Creature *actor, int direction);

    /**
     * Performs a single recursive quadrant scan for lighting to the north.
     * @param pos        is the origin position.
     * @param startAngle is the starting angle which also determines the starting location.
     * @param endAngle   is the ending angle which also determines the ending location.
     * @param iteration  is which iteration from the centre this begins at.
     * @param quadrant   is which direction to go in basically.
     */
    void lightScan(Position pos, float startAngle, float endAngle, int iteration, int quadrant);

public:
    static const unsigned char LAYER_PATH_SINK = 0;
    static const unsigned char LAYER_PATH_CARDINAL = 1;
    static const unsigned char LAYER_VIEW_FOV = 2;
    static const unsigned char LAYER_VIEW_TEMP = 3;
    static const unsigned char LAYER_SEEN = 4;
    static const unsigned char LAYER_N = 5;
    static const unsigned char LAYER_PATH_OFFSET = 0;
    static const unsigned char LAYER_VIEW_OFFSET = 2;
    static const unsigned char LAYER_PATH_N = 2;
    static const unsigned char LAYER_VIEW_N = 2;

    Colour bg = Colour::NAVY;
    Colour bump = Colour::NAVY / 2;


    /**
     * Creates the map as a square of given width and height.
     * @param dimensions is the width and height of the map.
     */
    Map(Position dimensions);

    /**
     * Deletes the junk.
     */
    ~Map();

    /**
     * Gives you the light value at a given spot.
     * @param pos is the spot to get the light at.
     * @return the light as a colour.
     */
    Colour getLight(Position pos) const;

    /**
     * Sets the light value at a given spot.
     * @param pos    is the position at which to set the light.
     * @param colour is the value to set the light to.
     */
    void setLight(Position pos, Colour colour);

    /**
     * Gets the floor tile object at a given location.
     * @param position is the location to get the floor for.
     * @return a pointer to the actual floor object.
     */
    const Floor *getFloor(Position pos) const;

    /**
     * sets a floor tile to belong to a given kind of floor.
     * @param floor is the floor that you want that tile to be.
     * @param pos   is the position of the tile you are changing.
     */
    void setFloor(const Floor *floor, Position pos);

    /**
     * Gets a wall tile.
     * @param pos is the location of the wall tile to get.
     */
    const Wall *getWall(Position pos) const;

    /**
     * Sets a wall tile to a given wall.
     * @param wall is the wall you are setting it to.
     * @param pos  is the location yu are changing.
     */
    void setWall(const Wall *wall, Position pos);

    /**
     * Gets a value from the layers of the map and hands it to you.
     * @param pos is the top down position to get the tile for.
     * @param z   is which layer to get the tile from.
     * @return the code that corresponds to something depending on the layer it is from.
     */
    unsigned char getTile(Position pos, int z) const;

    /**
     * Sets a tile to a value.
     * @param value    is the new value to set it to.
     * @param position is the top down location of the tile.
     * @param z        is which layer to get the tile from.
     */
    void setTile(unsigned char value, Position pos, int z);

    /**
     * Puts a creature into the map at the given location.
     * @param creature is the creature to add.
     * @param position is it's new location in the map.
     */
    void addCreature(Creature *creature, Position pos);

    /**
     * Applies a move to the map and alters it's state by it's effects.
     * @param move is the move to apply.
     */
    void applyMove(Move move);

    /**
     * Calculates all the generic pathfinding maps.
     * @param pos is the position of the player.
     */
    void pathing(Position pos);

    /**
     * Calculates all the lighting and line of sight for the map. NB: This is possibly going to change a bit.
     * @param pos is the position of the player.
     */
    void lighting(Position pos);

    /**
     * Goes through all creatures in the map that are ready to have a turn and applies their turns.
     */
    void update();

    /**
     * Renders the map to the screen in a bounded area.
     * @param graphics is the renderer.
     * @param rect     is the area the rendering must take place in.
     * @param middle   is what position should appear in the middle of the screen.
     */
    void render(Graphics *graphics, Rect rect, Position middle);
};

#endif
