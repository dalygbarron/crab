#include "Generator.hh"

#include <fstream>
#include "Map.hh"
#include "Content.hh"

/**
 * Generates a map full of randomised junk for a quick test.
 * @param depth     is not used here.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new map.
 */
Map *junk(int depth, int entrances) {
    Map *map = new Map(50, 50);
    for (int x = 0; x < 50; x++) {
        for (int y = 0; y < 50; y++) {
            map->setTile(1, x, y, Map::LAYER_FLOOR);
            map->setTile(0, x, y, Map::LAYER_WALL);
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
    return NULL;
}

/**
 * Generates a cave map.
 * @param depth     is how many levels of cave you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return a freshly made cave.
 */
Map *cave(int depth, int entrances) {
    return NULL;
}

/**
 * Generates a mansion kinda map.
 * @param depth     is how many levels of mansion you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new mansion map.
 */
Map *house(int depth, int entrances) {
    return NULL;
}

Map *Generator::generate(unsigned char type, int depth, int entrances) {
    switch(type) {
        case GENERATOR_JUNK: return junk(depth, entrances);
        case GENERATOR_SHIP: return ship(depth, entrances);
        case GENERATOR_CAVE: return cave(depth, entrances);
        case GENERATOR_HOUSE: return house(depth, entrances);
    }
    throw "invalid generator";
}
