#include "Generator.hh"

#include <fstream>
#include "Map.hh"
#include "inipp.hh"

/**
 * Generates a map full of randomised junk for a quick test.
 * @param assets    is used to get tiles.
 * @param depth     is not used here.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new map.
 */
Map *junk(const Assets *assets, int depth, int entrances) {
    Map *map = new Map(50, 50);
    const Floor *grass =
    return map;
}

/**
 * Generates a map consisting of space ships and that kind of shit.
 * @param assets    is used to get tiles.
 * @param depth     is how many levels of spaceship you have descended yet.
 * @param entrances is how many up stairs there must be in the map.
 * @return a fresh new spaceship map.
 */
Map *ship(const Assets *assets, int depth, int entrances) {
    return NULL;
}

/**
 * Generates a cave map.
 * @param assets    is used to get tiles.
 * @param depth     is how many levels of cave you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return a freshly made cave.
 */
Map *cave(const Assets *assets, int depth, int entrances) {
    return NULL;
}

/**
 * Generates a mansion kinda map.
 * @param assets    is used to get tiles.
 * @param depth     is how many levels of mansion you have descended so far.
 * @param entrances is how many up stairs there must be in the map.
 * @return the new mansion map.
 */
Map *house(const Assets *assets, int depth, int entrances) {
    return NULL;
}

Generator::Generator() {
	std::ifstream is("content/generator.ini");
	ini.parse(is);
}

Map *Generator::generate(const Assets *assets, unsigned char type, int depth, int entrances) {
    switch(type) {
        case GENERATOR_JUNK: return junk(depth, entrances);
        case GENERATOR_SHIP: return ship(depth, entrances);
        case GENERATOR_CAVE: return cave(depth, entrances);
        case GENERATOR_HOUSE: return house(depth, entrances);
    }
    throw "invalid generator";
}
