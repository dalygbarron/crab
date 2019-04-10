#ifndef GENERATOR_H
#define GENERATOR_H

/**
 * Forward declaration.
 */
class Map;

/**
 * Loads in parameters used for generating levels and also has functions for generating levels.
 */
class Generator {

public:
    static const unsigned char GENERATOR_JUNK = 0;
    static const unsigned char GENERATOR_SHIP = 1;
    static const unsigned char GENERATOR_CAVE = 2;
    static const unsigned char GENERATOR_HOUSE = 3;

    /**
     * Generates a new map for you of the given type and parameters.
     * @param type      is a code for the kind of generation algorithm to use. look at GENERATOR_* in this file.
     * @param depth     is how far down this map is as they get harder etc.
     * @return the new map for your pleasure.
     */
    Map *generate(unsigned char type, int depth = 1);
};

#endif
