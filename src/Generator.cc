#include "Generator.hh"
#include "inipp.h"

/**
 * Generates a map full of randomised junk for a quick test.
 * @param depth is not used here.
 * @return the new map.
 */
Map *junk(int depth) {
    Map *map = new Map(50, 50);
    return map;
}

/**
 * Generates a map consisting of space ships and that kind of shit.
 * @param depth is how many levels of spaceship you have descended yet.
 * @return a fresh new spaceship map.
 */
Map *ship(int depth) {
    return NULL;
}

/**
 * Generates a cave map.
 * @param depth is how many levels of cave you have descended so far.
 * @return a freshly made cave.
 */
Map *cave(int depth) {
    return NULL;
}

/**
 * Generates a mansion kinda map.
 * @param depth is how many levels of mansion you have descended so far.
 * @return the new mansion map.
 */
Map *house(int depth) {
    return NULL;
}

Generator::Generator() {
	std::ifstream is("content/generator.ini");
	ini.parse(is);
}

Map *Generator::generate(unsigned char type, int depth) {
    switch(type) {
        case GENERATOR_JUNK: return junk(depth);
        case GENERATOR_SHIP: return ship(depth);
        case GENERATOR_CAVE: return cave(depth);
        case GENERATOR_HOUSE: return house(depth);
    }
    return NULL;
}
