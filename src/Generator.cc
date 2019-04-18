#include "Generator.hh"

#include <fstream>
#include "Map.hh"
#include "Content.hh"

#define JUNK_THRESHOLD 50

/**
 * Generates a map full of randomised junk for a quick test.
 * @param content   is the container of the game content.
 * @param depth     is not used here.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new map.
 */
static Map *junk(const Content *content, int depth, int entrances) {
    Position dimensions(300, 300);
    Map *map = new Map(dimensions);
    for (int x = 0; x < dimensions.x; x++) {
        for (int y = 0; y < dimensions.y; y++) {
            Position pos(x, y);
            map->setFloor(content->getFloor(rand() % 2), pos);
            int choice = rand() % (JUNK_THRESHOLD + 2);
            if (choice < 2) map->setWall(content->getWall(choice), pos);
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
static Map *ship(int depth, int entrances) {
    return 0;
}

/**
 * Generates a cave map.
 * @param depth     is how many levels of cave you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return a freshly made cave.
 */
static Map *cave(int depth, int entrances) {
    return 0;
}

/**
 * Generates a mansion kinda map.
 * @param depth     is how many levels of mansion you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new mansion map.
 */
static Map *house(int depth, int entrances) {
    return 0;
}

Map *Generator::generate(const Content *content, unsigned char type, int depth) {
    switch(type) {
        case GENERATOR_JUNK: return junk(content, depth, 1);
        case GENERATOR_SHIP: return ship(depth, 1);
        case GENERATOR_CAVE: return cave(depth, 1);
        case GENERATOR_HOUSE: return house(depth, 1);
    }
    throw "invalid generator";
}
