#include "Generator.hh"

#include <fstream>
#include "Map.hh"
#include "Content.hh"

#define JUNK_THRESHOLD 3

/**
 * Generates a map full of randomised junk for a quick test.
 * @param depth     is not used here.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new map.
 */
Map *junk(int depth, int entrances) {
    Position dimensions(300, 300);
    Map *map = new Map(dimensions);
    for (int x = 0; x < dimensions.x; x++) {
        for (int y = 0; y < dimensions.y; y++) {
            Position pos(x, y);
            map->setTile(rand() % Content::FLOOR_N, pos, Map::LAYER_FLOOR);
            int choice = rand() % (JUNK_THRESHOLD + Content::WALL_N);
            if (choice >= Content::WALL_N) choice = 0;
            map->setTile(choice, pos, Map::LAYER_WALL);
        }
    }
    return map;
}

/**
 * Generates a map consisting of space ships and that kind of shit.
 * @param depth     is how many levels of spaceship you have descended yet.
 * @param entrances is how many up stairs there must be in the map.
 * @return a fresh new spaceship map.
 */
Map *ship(int depth, int entrances) {
    return 0;
}

/**
 * Generates a cave map.
 * @param depth     is how many levels of cave you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return a freshly made cave.
 */
Map *cave(int depth, int entrances) {
    return 0;
}

/**
 * Generates a mansion kinda map.
 * @param depth     is how many levels of mansion you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new mansion map.
 */
Map *house(int depth, int entrances) {
    return 0;
}

Map *Generator::generate(unsigned char type, int depth) {
    switch(type) {
        case GENERATOR_JUNK: return junk(depth, 1);
        case GENERATOR_SHIP: return ship(depth, 1);
        case GENERATOR_CAVE: return cave(depth, 1);
        case GENERATOR_HOUSE: return house(depth, 1);
    }
    throw "invalid generator";
}
