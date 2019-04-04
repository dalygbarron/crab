#ifndef CREATURE_H
#define CREATURE_H

/**
 * Prototypal creature that stores unchanging properties of a given kind of creature.
 */
class ProtoCreature {

};

/**
 * A living breathing creature in the game which walks around in the level and shit.
 */
class Creature {
    unsigned char prototype;
    unsigned short timer;

public:
    /**
     * Makes the creature by giving it a prototype to instantiate.
     * @param prototype is the index of the creature's prototype.
     */
    Creature(unsigned char prototype);
};

#endif
