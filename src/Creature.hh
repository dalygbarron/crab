#ifndef CREATURE_H
#define CREATURE_H

/**
 * A living breathing creature in the game which walks around in the level and shit.
 */
class Creature {
    const Prototype *prototype;
    unsigned short timer;

public:
    /**
     * Makes the creature by giving it a prototype to instantiate.
     * @param prototype is the kind of creature this creature is.
     */
    Creature(Prototype *prototype);
};

#endif
