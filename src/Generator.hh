#ifndef GENERATOR_H
#define GENERATOR_H

#include "inipp.hh"

/**
 * Forward declaration.
 */
class Map;

/**
 * Loads in parameters used for generating levels and also has functions for generating levels.
 */
class Generator {
    inipp::Ini<char> ini;

public:
    static const unsigned char GENERATOR_JUNK = 0;
    static const unsigned char GENERATOR_SHIP = 1;
    static const unsigned char GENERATOR_CAVE = 2;
    static const unsigned char GENERATOR_HOUSE = 3;

    /**
     * Creates the generator and loads in the generator ini for configuration hell yeah.
     */
    Generator();

    /**
     * Generates a new map for you of the given type and parameters.
     * @param assets    is used to get the tiles and stuff.
     * @param type      is a code for the kind of generation algorithm to use. look at GENERATOR_* in this file.
     * @param depth     is how far down this map is as they get harder etc.
     * @param entrances is the number of up stairs this area must have.
     * @return the new map for your pleasure.
     */
    Map *generate(const Assets *assets, unsigned char type, int depth = 1, int entrances = 0);
};

#endif
