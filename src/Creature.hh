#ifndef CREATURE_H
#define CREATURE_H

#include "Mob.hh"
#include "Move.hh"
#include "Map.hh"
#include "Graphics.hh"

/**
 * Prototypal creature that stores unchanging properties of a given kind of creature.
 */
class ProtoCreature {
public:
    static const int TEMPERAMENT_THING = 0;
    static const int TEMPERAMENT_GRUNT = 1;
    static const int TEMPERAMENT_N = 2;

    static const int BONUS_NONE = 0;
    static const int BONUS_SWOLE = 1;
    static const int BONUS_RED = 2;

    const char *name;
    const char *description;
    int constitution;
    int intelligence;
    int strength;
    int mobility;
    unsigned char tile;
    Colour colour;
    int temperament;
    int rating;

    /**
     * Blank constructor for nothing creature.
     */
    ProtoCreature();
};

/**
 * A living breathing creature in the game which walks around in the level and shit.
 */
class Creature: public Mob {
    const ProtoCreature *prototype;
    unsigned short timer = 0;

public:
    /**
     * Makes the creature by giving it a prototype to instantiate.
     * @param prototype is the prototypal creature this one is based on.
     */
    Creature(const ProtoCreature *prototype);

    /**
     * Asks the creature what they would like to do this turn.
     * @param Map is the map that they are in as it is at the time of their move.
     */
    virtual Move getMove(Map const *map);
};

#endif
