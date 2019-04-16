#ifndef GENERATOR_H
#define GENERATOR_H

/**
 * Forward declaration.
 */
class Map;

/**
 * Loads in parameters used for generating levels and also has functions for generating levels.
 */
namespace Generator {
    const unsigned char GENERATOR_JUNK = 0;
    const unsigned char GENERATOR_SHIP = 1;
    const unsigned char GENERATOR_CAVE = 2;
    const unsigned char GENERATOR_HOUSE = 3;

    /**
     * Generates a new map for you of the given type and parameters.
     * @param content   contains the content holder.
     * @param type      is a code for the kind of generation algorithm to use. look at GENERATOR_* in this file.
     * @param depth     is how far down this map is as they get harder etc.
     * @return the new map for your pleasure.
     */
    Map *generate(Content *content, unsigned char type, int depth = 1);
};

#endif
